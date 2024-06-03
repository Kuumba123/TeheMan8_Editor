--========================================================
--			LUA SCRIPT for MM8 Various Things [Redux]	--
--          made by PogChampGuy aka Kuumba              --
--========================================================

mm8 ={
    --Redux Variables
	mem = PCSX.getMemPtr(),
	cache = PCSX.getScratchPtr(),
	scaleX = 0,
	scaleY = 0,
	megaX = 0,
	megaY = 0,
    megaX = 0,
	megaY = 0,
	--Cam Vars
	camX = 0,
	camY = 0,
	pastCamX = 0,
	pastCamY = 0,
	bg2X = 0,
	bg2Y = 0,
	bg3X = 0,
	bg3Y = 0,
    MEGA_ADDR = 0x15e23c,
    BG_ADDR = 0x1d2914,
    	--Object Constatns
    MAIN_OBJ_ADDR = 0x15b174,
	EFFECT_OBJ_ADDR = 0x1cf540,
    --Collision Checkboxes
	showCollision = false,
    --Object Checkboxes
	showWepObj = true,
    showEffectWep = true,
	showMainObj = true,
    showMiscObj = true,
    showItemObj = true,
    showEffectObj = true,
    showRush = true,
    objectOption = 1
}

function mm8:AssignVariables()
    mm8.megaX = bit.band(ffi.cast('short*', (mm8.mem + mm8.MEGA_ADDR + 14))[0],0xFFFF)
    mm8.megaY = bit.band(ffi.cast('short*', mm8.mem + mm8.MEGA_ADDR + 18)[0],0xFFFF)

	mm8.camX = bit.band(ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 6)[0],0xFFFF)
	mm8.camY = bit.band(ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 8)[0],0xFFFF)
	mm8.pastCamX  = bit.band(ffi.cast('short*', mm8.mem + 0x16ec0c)[0],0xFFFF)
	mm8.pastCamY  = bit.band(ffi.cast('short*', mm8.mem + 0x16ec10)[0],0xFFFF)
	mm8.bg2X = bit.band(ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 6 + 48)[0],0xFFFF)
	mm8.bg2Y = bit.band(ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 8 + 48)[0],0xFFFF)

	mm8.bg3X = bit.band(ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 6 + 48 * 2)[0],0xFFFF)
	mm8.bg3Y = bit.band(ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 8 + 48 * 2)[0],0xFFFF)
end

function mm8:CheckObjectMem(addr, slots, size,winX,winY,r , g, b)
    for i = 0, slots do
        local alive = ffi.cast("uint8_t*", mm8.mem + (i * size) + addr)[0]
        if alive ~= 0 then
            local id = ffi.cast('uint8_t*', mm8.mem + (i * size) + addr + 6)[0]
            local objX = ffi.cast('short*', mm8.mem + (i * size) + addr + 14)[0]
            local objY = ffi.cast('short*', mm8.mem + (i * size) + addr + 18)[0]

			if mm8.objectOption == 2 then
				id = ffi.cast('uint8_t*', mm8.mem + (i * size) + addr + 7)[0]
			elseif mm8.objectOption == 3 then
				id = i
			end
            local s = string.upper(string.format("%02x", id))
            local adjustedX = winX + ((objX - mm8.pastCamX) * mm8.scaleX)
            local adjustedY = winY + ((objY - mm8.pastCamY) * mm8.scaleY)
            local adjustedW = 22 * mm8.scaleX
            local adjustedH = 22 * mm8.scaleY

            -- Draw Rectangle
            nvg:beginPath()
            nvg:rect(adjustedX, adjustedY - adjustedH, adjustedW, adjustedH)
            nvg:fillColor(nvg.RGBA(r, g, b, 96))
            nvg:fill()

            -- Draw Text
            nvg:beginPath()
			nvg:fillColor(nvg.RGBA(255, 255, 255, 255))
			nvg:fontSize(20 * mm8.scaleX)
            nvg:text(adjustedX, adjustedY, s)

            nvg:fill()
        end
    end
end

function mm8:DrawCollision(winX,winY)

	for y = 0, 16 do
		for x = 0, 19 do
			local layoutOffset = bit.rshift((mm8.camX + x * 16),8) + bit.rshift((mm8.camY + y * 16),8) * 32 + 0x16ef34

			local screenId = mm8.mem[layoutOffset]

			local screenDataP = 0x171c3c
			local tileInfoP = 0x15ea88

			local tileId = bit.band(ffi.cast("short*",mm8.mem + screenDataP + screenId * 0x200)[bit.rshift(bit.band(mm8.camX + x * 16, 0xF0),4) + bit.band(mm8.camY + y * 16,0xF0)],0xFFF)

			local collisionId = bit.band(ffi.cast("uint8_t*",mm8.mem + tileInfoP + tileId * 4)[3],0xFF)

			--Solid Tile
			if collisionId == 0x3D then
				local drawX = (x * 16 - bit.band(mm8.camX,0xF)) * mm8.scaleX + winX
				local drawY = (y * 16 - bit.band(mm8.camY,0xF)) * mm8.scaleY + winY

				nvg:beginPath()
				nvg:rect(drawX, drawY, 16 * mm8.scaleX, 16 * mm8.scaleY)
				nvg:strokeColor(nvg.RGBA(0, 0, 255, 128))
				nvg:strokeWidth(2)
				nvg:stroke()
			elseif collisionId == 0x3E or collisionId == 0x3F then
				local drawX = (x * 16 - bit.band(mm8.camX,0xF)) * mm8.scaleX + winX
				local drawY = (y * 16 - bit.band(mm8.camY,0xF)) * mm8.scaleY + winY

				nvg:beginPath()
				nvg:rect(drawX, drawY, 16 * mm8.scaleX, 16 * mm8.scaleY)
				nvg:strokeColor(nvg.RGBA(255, 0, 0, 128))
				nvg:strokeWidth(2)
				nvg:stroke()				
			end
		end
	end
end


function mm8:DrawGeneral()
    local isHeaderOpen = imgui.CollapsingHeader("General")
    if isHeaderOpen then
        local mode = ffi.cast("uint8_t*", mm8.mem + 0x1cf840)[0]
        local mode2 = ffi.cast("uint8_t*", mm8.mem + 0x1cf844)[0]
    end
end


function mm8:DrawMegaManInfo()
end

function mm8:DrawBackgroundHeaders()
    local isHeaderOpen = imgui.CollapsingHeader("Background 1 Settings")
    if isHeaderOpen then
        imgui.TextUnformatted("X:" .. string.upper(string.format("%04x", mm8.camX)))
        imgui.TextUnformatted("Y:" .. string.upper(string.format("%04x", mm8.camY)))
        imgui.TextUnformatted("Enabled: ")
        imgui.SameLine()
        if mm8.mem[mm8.BG_ADDR + 0] == 0 then
            imgui.TextUnformatted("FALSE")
        else
            imgui.TextUnformatted("TRUE")
        end

        imgui.TextUnformatted("Scroll Type: " .. mm8.mem[mm8.BG_ADDR + 1])

        imgui.TextUnformatted("Border-Right: " .. string.upper(string.format("%04x", ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 18)[0])))
        imgui.TextUnformatted("Border-Left: " .. string.upper(string.format("%04x", ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 18)[1])))
        imgui.TextUnformatted("Border-Bottom: " .. string.upper(string.format("%04x", ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 18)[2])))
        imgui.TextUnformatted("Border-Top: " .. string.upper(string.format("%04x", ffi.cast('short*', mm8.mem + mm8.BG_ADDR + 18)[3])))
        local changed, value = imgui.Checkbox("Show Collision", mm8.showCollision)
        if changed then
            mm8.showCollision = value
        end
    end

    isHeaderOpen = imgui.CollapsingHeader("Background 2 Settings")
    if isHeaderOpen then
        imgui.TextUnformatted("X:" .. string.upper(string.format("%04x", mm8.bg2X)))
        imgui.TextUnformatted("Y:" .. string.upper(string.format("%04x", mm8.bg2Y)))
        imgui.TextUnformatted("Enabled: ")
        imgui.SameLine()
        if mm8.mem[mm8.BG_ADDR + 0 + 48] == 0 then
            imgui.TextUnformatted("FALSE")
        else
            imgui.TextUnformatted("TRUE")
        end

        imgui.TextUnformatted("Scroll Type: " .. string.format("%X",mm8.mem[mm8.BG_ADDR + 1 + 48]))
    end

    isHeaderOpen = imgui.CollapsingHeader("Background 3 Settings")
    if isHeaderOpen then
        imgui.TextUnformatted("X:" .. string.upper(string.format("%04x", mm8.bg3X)))
        imgui.TextUnformatted("Y:" .. string.upper(string.format("%04x", mm8.bg3Y)))
        imgui.TextUnformatted("Enabled: ")
        imgui.SameLine()
        if mm8.mem[mm8.BG_ADDR + 0 + 48 * 2] == 0 then
            imgui.TextUnformatted("FALSE")
        else
            imgui.TextUnformatted("TRUE")
        end

        imgui.TextUnformatted("Scroll Type: " .. string.format("%X",mm8.mem[mm8.BG_ADDR + 4 + 48 * 1]))
    end
end

function mm8:DrawObjectControls()
    local isHeaderOpen = imgui.CollapsingHeader("Object Settings")
    if isHeaderOpen then
        changed, value = imgui.Checkbox("Weapon Objects", mm8.showWepObj)
        if changed then
            mm8.showWepObj = value
        end
        changed, value = imgui.Checkbox("Weapon Effect Objects", mm8.showEffectWep)
        if changed then
            mm8.showEffectWep = value
        end
        changed, value = imgui.Checkbox("Main Objects", mm8.showMainObj)
        if changed then
            mm8.showMainObj = value
        end
        changed, value = imgui.Checkbox("Item Objects", mm8.showItemObj)
        if changed then
            mm8.showItemObj = value
        end
        changed, value = imgui.Checkbox("Misc Objects", mm8.showMiscObj)
        if changed then
            mm8.showMiscObj = value
        end
        changed, value = imgui.Checkbox("Effect Objects", mm8.showEffectObj)
        if changed then
            mm8.showEffectObj = value
        end
        changed, value = imgui.Checkbox("Show Rush", mm8.showRush)
        if changed then
            mm8.showRush = value
        end

        -- Create radio buttons for Id/Var/Slot
        if imgui.RadioButton("Id", mm8.objectOption == 1) then
            mm8.objectOption = 1
        end
        imgui.SameLine()
        if imgui.RadioButton("Var", mm8.objectOption == 2) then
            mm8.objectOption = 2
        end
        imgui.SameLine()
        if imgui.RadioButton("Slot", mm8.objectOption == 3) then
            mm8.objectOption = 3
        end
    end
end

function DrawImguiFrame()

	imgui.Begin('MegaMan 8 Tools', false)

	mm8:AssignVariables()
	mm8:DrawGeneral()
	mm8:DrawMegaManInfo()
	mm8:DrawBackgroundHeaders()
	mm8:DrawObjectControls()
	imgui.End()

end

function mm8:unload()
	DrawImguiFrame = nil
	PCSX.GUI.OutputShader.setDefaults()
	for key, _ in pairs(mm8) do
		mm8[key] = nil
	end
	mm8.unload = nil
end

PCSX.GUI.OutputShader.setTextL([[function Image(textureID, srcSizeX, srcSizeY, dstSizeX, dstSizeY)
	local winX, winY = PCSX.Helpers.UI.imageCoordinates(0, 0, 1.0, 1.0, dstSizeX, dstSizeY)
	-- Calculate the scaling factor based on the desired width (e.g., 320 pixels)
	mm8.scaleX = dstSizeX / 320
	mm8.scaleY = dstSizeY / 240

    nvg:queueNvgRender(function()
        if mm8.showCollision then
            mm8:DrawCollision(winX,winY)
        end
        if mm8.showWepObj then
            mm8:CheckObjectMem(0x1b12ac,0x20,0x60,winX,winY,0,0xFF,0)
        end
        if mm8.showEffectWep then
            mm8:CheckObjectMem(0x1d184c,0x20,0x10,winX,winY,0,0xFF,0xFF)
        end
        if mm8.showMainObj then
            mm8:CheckObjectMem(0x15b174,0x40,0x60,winX,winY,255,0,0)
        end
        if mm8.showItemObj then
            mm8:CheckObjectMem(0x1b1eec,0x20,0x50,winX,winY,0,0,255)
        end
		if mm8.showMiscObj then
			mm8:CheckObjectMem(0x1cf848,0x80,0x40,winX,winY,0x8A,0x2B,0xE2)
		end
        if mm8.showEffectObj then
			mm8:CheckObjectMem(0x1cf540,0x18,0x20,winX,winY,0xFF,0x14,0x93)
		end
        if mm8.showRush then
            mm8:CheckObjectMem(0x1d2890, 1,0x1,winX ,winY,0x69,0,0)
        end
	end)

    imgui.Image(textureID, dstSizeX, dstSizeY, 0, 0, 1, 1)
end
]]
)