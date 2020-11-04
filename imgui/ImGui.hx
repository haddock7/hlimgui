package imgui;

abstract ExtDynamic<T>(Dynamic) from T to T {}

@:enum abstract ImGuiWindowFlags(Int) from Int to Int {
	var None : Int = 0;
	var NoTitleBar : Int = 1;
	var NoResize : Int = 2;
	var NoMove : Int = 4;
	var NoScrollbar : Int = 8;
	var NoScrollWithMouse : Int = 16;
	var NoCollapse : Int = 32;
	var AlwaysAutoResize : Int = 64;
	var NoBackground : Int = 128;
	var NoSavedSettings : Int = 256;
	var NoMouseInputs : Int = 512;
	var MenuBar : Int = 1024;
	var HorizontalScrollbar : Int = 2048;
	var NoFocusOnAppearing : Int = 4096;
	var NoBringToFrontOnFocus : Int = 8192;
	var AlwaysVerticalScrollbar : Int = 16384;
	var AlwaysHorizontalScrollbar : Int = 32768;
	var AlwaysUseWindowPadding : Int = 65536;
	var NoNavInputs : Int = 262144;
	var NoNavFocus : Int = 524288;
	var UnsavedDocument : Int = 1048576;
	var NoNav : Int = 786432;
	var NoDecoration : Int = 43;
	var NoInputs : Int = 786944;
}

@:enum abstract ImGuiDockNodeFlags(Int) from Int to Int {
	var None : Int = 0;
	var KeepAliveOnly : Int = 1;
	var NoCentralNode : Int = 2;
	var NoDockingInCentralNode : Int = 4;
	var NoSplit : Int = 8;
	var NoResize : Int = 16;
	var PassthruCentralNode : Int = 32;
	var AutoHideTabBar : Int = 64;
}

@:enum abstract ImGuiTreeNodeFlags(Int) from Int to Int {
	var None : Int = 0;
	var Selected : Int = 1;
	var Framed : Int = 2;
	var AllowItemOverlap : Int = 4;
	var NoTreePushOnOpen : Int = 8;
	var NoAutoOpenOnLog : Int = 16;
	var DefaultOpen : Int = 32;
	var OpenOnDoubleClick : Int = 64;
	var OpenOnArrow : Int = 128;
	var Leaf : Int = 256;
	var Bullet : Int = 512;
	var FramePadding : Int = 1024;
	var SpanAvailWidth : Int = 2048;
	var SpanFullWidth : Int = 4096;
	var NavLeftJumpsBackHere : Int = 8192;
	var CollapsingHeader : Int = 26;
}

@:enum abstract ImGuiTabItemFlags(Int) from Int to Int {
	var None : Int = 0;
	var UnsavedDocument : Int = 1;
	var SetSelected : Int = 2;
	var NoCloseWithMiddleMouseButton : Int = 4;
	var NoPushId : Int = 8;
}

@:enum abstract ImGuiTabBarFlags(Int) from Int to Int {
	var None : Int = 0;
	var Reorderable : Int = 1;
	var AutoSelectNewTabs : Int = 2;
	var TabListPopupButton : Int = 4;
	var NoCloseWithMiddleMouseButton : Int = 8;
	var NoTabListScrollingButtons : Int = 16;
	var NoTooltip : Int = 32;
	var FittingPolicyResizeDown : Int = 64;
	var FittingPolicyScroll : Int = 128;
	var FittingPolicyMask_ : Int = 192;
	var FittingPolicyDefault_ : Int = 64;
}

@:enum abstract ImGuiStyleVar(Int) from Int to Int {
	var Alpha : Int = 0;
	var WindowPadding : Int = 1;
	var WindowRounding : Int = 2;
	var WindowBorderSize : Int = 3;
	var WindowMinSize : Int = 4;
	var WindowTitleAlign : Int = 5;
	var ChildRounding : Int = 6;
	var ChildBorderSize : Int = 7;
	var PopupRounding : Int = 8;
	var PopupBorderSize : Int = 9;
	var FramePadding : Int = 10;
	var FrameRounding : Int = 11;
	var FrameBorderSize : Int = 12;
	var ItemSpacing : Int = 13;
	var ItemInnerSpacing : Int = 14;
	var IndentSpacing : Int = 15;
	var ScrollbarSize : Int = 16;
	var ScrollbarRounding : Int = 17;
	var GrabMinSize : Int = 18;
	var GrabRounding : Int = 19;
	var TabRounding : Int = 20;
	var ButtonTextAlign : Int = 21;
	var SelectableTextAlign : Int = 22;
	var COUNT : Int = 23;
}

@:enum abstract ImGuiSelectableFlags(Int) from Int to Int {
	var None : Int = 0;
	var DontClosePopups : Int = 1;
	var SpanAllColumns : Int = 2;
	var AllowDoubleClick : Int = 4;
	var Disabled : Int = 8;
	var AllowItemOverlap : Int = 16;
}

@:enum abstract ImGuiNavInput(Int) from Int to Int {
	var Activate : Int = 0;
	var Cancel : Int = 1;
	var Input : Int = 2;
	var Menu : Int = 3;
	var DpadLeft : Int = 4;
	var DpadRight : Int = 5;
	var DpadUp : Int = 6;
	var DpadDown : Int = 7;
	var LStickLeft : Int = 8;
	var LStickRight : Int = 9;
	var LStickUp : Int = 10;
	var LStickDown : Int = 11;
	var FocusPrev : Int = 12;
	var FocusNext : Int = 13;
	var TweakSlow : Int = 14;
	var TweakFast : Int = 15;
	var KeyMenu_ : Int = 16;
	var KeyLeft_ : Int = 17;
	var KeyRight_ : Int = 18;
	var KeyUp_ : Int = 19;
	var KeyDown_ : Int = 20;
	var COUNT : Int = 21;
	var InternalStart_ : Int = 16;
}

@:enum abstract ImGuiMouseCursor(Int) from Int to Int {
	var None : Int = -1;
	var Arrow : Int = 0;
	var TextInput : Int = 1;
	var ResizeAll : Int = 2;
	var ResizeNS : Int = 3;
	var ResizeEW : Int = 4;
	var ResizeNESW : Int = 5;
	var ResizeNWSE : Int = 6;
	var Hand : Int = 7;
	var NotAllowed : Int = 8;
	var COUNT : Int = 9;
}

@:enum abstract ImGuiMouseButton(Int) from Int to Int {
	var Left : Int = 0;
	var Right : Int = 1;
	var Middle : Int = 2;
	var COUNT : Int = 5;
}

@:enum abstract ImGuiKey(Int) from Int to Int {
	var Tab : Int = 0;
	var LeftArrow : Int = 1;
	var RightArrow : Int = 2;
	var UpArrow : Int = 3;
	var DownArrow : Int = 4;
	var PageUp : Int = 5;
	var PageDown : Int = 6;
	var Home : Int = 7;
	var End : Int = 8;
	var Insert : Int = 9;
	var Delete : Int = 10;
	var Backspace : Int = 11;
	var Space : Int = 12;
	var Enter : Int = 13;
	var Escape : Int = 14;
	var KeyPadEnter : Int = 15;
	var A : Int = 16;
	var C : Int = 17;
	var V : Int = 18;
	var X : Int = 19;
	var Y : Int = 20;
	var Z : Int = 21;
	var COUNT : Int = 22;
}

@:enum abstract ImGuiInputTextFlags(Int) from Int to Int {
	var None : Int = 0;
	var CharsDecimal : Int = 1;
	var CharsHexadecimal : Int = 2;
	var CharsUppercase : Int = 4;
	var CharsNoBlank : Int = 8;
	var AutoSelectAll : Int = 16;
	var EnterReturnsTrue : Int = 32;
	var CallbackCompletion : Int = 64;
	var CallbackHistory : Int = 128;
	var CallbackAlways : Int = 256;
	var CallbackCharFilter : Int = 512;
	var AllowTabInput : Int = 1024;
	var CtrlEnterForNewLine : Int = 2048;
	var NoHorizontalScroll : Int = 4096;
	var AlwaysInsertMode : Int = 8192;
	var ReadOnly : Int = 16384;
	var Password : Int = 32768;
	var NoUndoRedo : Int = 65536;
	var CharsScientific : Int = 131072;
	var CallbackResize : Int = 262144;
	var Multiline : Int = 1048576;
	var NoMarkEdited : Int = 2097152;
}

@:enum abstract ImGuiHoveredFlags(Int) from Int to Int {
	var None : Int = 0;
	var ChildWindows : Int = 1;
	var RootWindow : Int = 2;
	var AnyWindow : Int = 4;
	var AllowWhenBlockedByPopup : Int = 8;
	var AllowWhenBlockedByActiveItem : Int = 32;
	var AllowWhenOverlapped : Int = 64;
	var AllowWhenDisabled : Int = 128;
	var RectOnly : Int = 104;
	var RootAndChildWindows : Int = 3;
}

@:enum abstract ImGuiFocusedFlags(Int) from Int to Int {
	var None : Int = 0;
	var ChildWindows : Int = 1;
	var RootWindow : Int = 2;
	var AnyWindow : Int = 4;
	var RootAndChildWindows : Int = 3;
}

@:enum abstract ImGuiDragDropFlags(Int) from Int to Int {
	var None : Int = 0;
	var SourceNoPreviewTooltip : Int = 1;
	var SourceNoDisableHover : Int = 2;
	var SourceNoHoldToOpenOthers : Int = 4;
	var SourceAllowNullID : Int = 8;
	var SourceExtern : Int = 16;
	var SourceAutoExpirePayload : Int = 32;
	var AcceptBeforeDelivery : Int = 1024;
	var AcceptNoDrawDefaultRect : Int = 2048;
	var AcceptNoPreviewTooltip : Int = 4096;
	var AcceptPeekOnly : Int = 3072;
}

@:enum abstract ImGuiDir(Int) from Int to Int {
	var None : Int = -1;
	var Left : Int = 0;
	var Right : Int = 1;
	var Up : Int = 2;
	var Down : Int = 3;
	var COUNT : Int = 4;
}

@:enum abstract ImGuiDataType(Int) from Int to Int {
	var S8 : Int = 0;
	var U8 : Int = 1;
	var S16 : Int = 2;
	var U16 : Int = 3;
	var S32 : Int = 4;
	var U32 : Int = 5;
	var S64 : Int = 6;
	var U64 : Int = 7;
	var Float : Int = 8;
	var Double : Int = 9;
	var COUNT : Int = 10;
}

@:enum abstract ImGuiConfigFlags(Int) from Int to Int {
	var None : Int = 0;
	var NavEnableKeyboard : Int = 1;
	var NavEnableGamepad : Int = 2;
	var NavEnableSetMousePos : Int = 4;
	var NavNoCaptureKeyboard : Int = 8;
	var NoMouse : Int = 16;
	var NoMouseCursorChange : Int = 32;
	var DockingEnable : Int = 64;
	var ViewportsEnable : Int = 1024;
	var IsSRGB : Int = 1048576;
	var IsTouchScreen : Int = 2097152;
}

@:enum abstract ImGuiCond(Int) from Int to Int {
	var Always : Int = 1;
	var Once : Int = 2;
	var FirstUseEver : Int = 4;
	var Appearing : Int = 8;
}

@:enum abstract ImGuiComboFlags(Int) from Int to Int {
	var None : Int = 0;
	var PopupAlignLeft : Int = 1;
	var HeightSmall : Int = 2;
	var HeightRegular : Int = 4;
	var HeightLarge : Int = 8;
	var HeightLargest : Int = 16;
	var NoArrowButton : Int = 32;
	var NoPreview : Int = 64;
	var HeightMask_ : Int = 30;
}

@:enum abstract ImGuiColorEditFlags(Int) from Int to Int {
	var None : Int = 0;
	var NoAlpha : Int = 2;
	var NoPicker : Int = 4;
	var NoOptions : Int = 8;
	var NoSmallPreview : Int = 16;
	var NoInputs : Int = 32;
	var NoTooltip : Int = 64;
	var NoLabel : Int = 128;
	var NoSidePreview : Int = 256;
	var NoDragDrop : Int = 512;
	var AlphaBar : Int = 65536;
	var AlphaPreview : Int = 131072;
	var AlphaPreviewHalf : Int = 262144;
	var HDR : Int = 524288;
	var DisplayRGB : Int = 1048576;
	var DisplayHSV : Int = 2097152;
	var DisplayHex : Int = 4194304;
	var Uint8 : Int = 8388608;
	var Float : Int = 16777216;
	var PickerHueBar : Int = 33554432;
	var PickerHueWheel : Int = 67108864;
	var InputRGB : Int = 134217728;
	var InputHSV : Int = 268435456;
	var _OptionsDefault : Int = 177209344;
	var _DisplayMask : Int = 7340032;
	var _DataTypeMask : Int = 25165824;
	var _PickerMask : Int = 100663296;
	var _InputMask : Int = 402653184;
}

@:enum abstract ImGuiCol(Int) from Int to Int {
	var Text : Int = 0;
	var TextDisabled : Int = 1;
	var WindowBg : Int = 2;
	var ChildBg : Int = 3;
	var PopupBg : Int = 4;
	var Border : Int = 5;
	var BorderShadow : Int = 6;
	var FrameBg : Int = 7;
	var FrameBgHovered : Int = 8;
	var FrameBgActive : Int = 9;
	var TitleBg : Int = 10;
	var TitleBgActive : Int = 11;
	var TitleBgCollapsed : Int = 12;
	var MenuBarBg : Int = 13;
	var ScrollbarBg : Int = 14;
	var ScrollbarGrab : Int = 15;
	var ScrollbarGrabHovered : Int = 16;
	var ScrollbarGrabActive : Int = 17;
	var CheckMark : Int = 18;
	var SliderGrab : Int = 19;
	var SliderGrabActive : Int = 20;
	var Button : Int = 21;
	var ButtonHovered : Int = 22;
	var ButtonActive : Int = 23;
	var Header : Int = 24;
	var HeaderHovered : Int = 25;
	var HeaderActive : Int = 26;
	var Separator : Int = 27;
	var SeparatorHovered : Int = 28;
	var SeparatorActive : Int = 29;
	var ResizeGrip : Int = 30;
	var ResizeGripHovered : Int = 31;
	var ResizeGripActive : Int = 32;
	var Tab : Int = 33;
	var TabHovered : Int = 34;
	var TabActive : Int = 35;
	var TabUnfocused : Int = 36;
	var TabUnfocusedActive : Int = 37;
	var PlotLines : Int = 38;
	var PlotLinesHovered : Int = 39;
	var PlotHistogram : Int = 40;
	var PlotHistogramHovered : Int = 41;
	var TextSelectedBg : Int = 42;
	var DragDropTarget : Int = 43;
	var NavHighlight : Int = 44;
	var NavWindowingHighlight : Int = 45;
	var NavWindowingDimBg : Int = 46;
	var ModalWindowDimBg : Int = 47;
	var COUNT : Int = 48;
}

@:enum abstract ImGuiBackendFlags(Int) from Int to Int {
	var None : Int = 0;
	var HasGamepad : Int = 1;
	var HasMouseCursors : Int = 2;
	var HasSetMousePos : Int = 4;
	var RendererHasVtxOffset : Int = 8;
}

@:enum abstract ImFontAtlasFlags(Int) from Int to Int {
	var None : Int = 0;
	var NoPowerOfTwoHeight : Int = 1;
	var NoMouseCursors : Int = 2;
}

@:enum abstract ImDrawListFlags(Int) from Int to Int {
	var None : Int = 0;
	var AntiAliasedLines : Int = 1;
	var AntiAliasedFill : Int = 2;
	var AllowVtxOffset : Int = 4;
}

@:enum abstract ImDrawCornerFlags(Int) from Int to Int {
	var None : Int = 0;
	var TopLeft : Int = 1;
	var TopRight : Int = 2;
	var BotLeft : Int = 4;
	var BotRight : Int = 8;
	var Top : Int = 3;
	var Bot : Int = 12;
	var Left : Int = 5;
	var Right : Int = 10;
	var All : Int = 15;
}

typedef ImEvents = {
	dt : Single,
	mouse_x : Single,
	mouse_y : Single,
	wheel : Single,
	left_click : Bool,
	right_click : Bool,
	shift : Bool,
	ctrl : Bool,
	alt : Bool
}

typedef ImTextureID = Int;
typedef ImU32 = Int;
typedef ImGuiID = Int;

typedef ImVec2 = {
	x : Single,
	y : Single
}

typedef ImVec4 = {
	x : Single,
	y : Single,
	z : Single,
	w : Single
}

typedef ImGuiStyle = {
    Alpha : Single,
    WindowPadding : ImVec2,
    WindowRounding : Single,
    WindowBorderSize : Single,
    WindowMinSize : ImVec2,
    WindowTitleAlign : ImVec2,
    WindowMenuButtonPosition : ImGuiDir,
    ChildRounding : Single,
    ChildBorderSize : Single,
    PopupRounding : Single,
    PopupBorderSize : Single,
    FramePadding : ImVec2,
    FrameRounding : Single,
    FrameBorderSize : Single,
    ItemSpacing : ImVec2,
    ItemInnerSpacing : ImVec2,
    TouchExtraPadding : ImVec2,
    IndentSpacing : Single,
    ColumnsMinSpacing : Single,
    ScrollbarSize : Single,
    ScrollbarRounding : Single,
    GrabMinSize : Single,
    GrabRounding : Single,
    TabRounding : Single,
    TabBorderSize : Single,
    TabMinWidthForCloseButton : Single,
    ColorButtonPosition : ImGuiDir,
    ButtonTextAlign : ImVec2,
    SelectableTextAlign : ImVec2,
    DisplayWindowPadding : ImVec2,
    DisplaySafeAreaPadding : ImVec2,
    MouseCursorScale : Single,
    AntiAliasedLines : Bool,
    AntiAliasedFill : Bool,
    CurveTessellationTol : Single,
    CircleSegmentMaxError : Single,
    Colors : hl.NativeArray<ImVec4>
};


@:hlNative("hlimgui")
class ImGui
{
	public static inline var FLT_MAX = 3.402823466e+38;

	// Context
    public static function createContext() : hl.Bytes {return null;}
    public static function destroyContext(ctx : hl.Bytes = null) {}
    public static function getCurrentContext() : hl.Bytes {return null;}
	public static function setCurrentContext(ctx : hl.Bytes) {}
	
	// Main
	public static function getStyle() : ExtDynamic<ImGuiStyle> {return null;}
	public static function setStyle(style : ExtDynamic<ImGuiStyle>) {}
	public static function newFrame() {}
	public static function endFrame() {}
	public static function render() {}

	// Demo, Debug, Information
    public static function showDemoWindow(open : hl.Ref<Bool> = null) {}
    public static function showAboutWindow(open : hl.Ref<Bool> = null) {}
	public static function showMetricsWindow(open : hl.Ref<Bool> = null) {}
	public static function showStyleEditor(style : ExtDynamic<ImGuiStyle> = null) {}
    public static function showStyleSelector(label : String) : Bool {return false;}
    public static function showFontSelector(label : String) {}
	public static function showUserGuide() {}
	static function get_version() : hl.Bytes {return null;}
    public static function getVersion() : String {
		return @:privateAccess String.fromUTF8(get_version());
	}

	// styles
	public static function styleColorsDark(style : ExtDynamic<ImGuiStyle> = null) {}
    public static function styleColorsClassic(style : ExtDynamic<ImGuiStyle> = null) {}
    public static function styleColorsLight(style : ExtDynamic<ImGuiStyle> = null) {}

	// windows
    public static function begin(name : String, open : hl.Ref<Bool> = null, flags : ImGuiWindowFlags = 0) : Bool {return false;}
	public static function end() {}

	// Child windows
    public static function beginChild(str_id : String, size : ExtDynamic<ImVec2> = null, border : Bool = false, flags : ImGuiWindowFlags = 0) : Bool {return false;}
    public static function beginChild2(id : Int, size : ExtDynamic<ImVec2> = null, border : Bool = false, flags : ImGuiWindowFlags = 0) : Bool {return false;}
	public static function endChild() {}
	
	// Windows utilities
	public static function isWindowAppearing() : Bool {return false;}
    public static function isWindowCollapsed() : Bool {return false;}
    public static function isWindowFocused(flags : ImGuiFocusedFlags = 0) {return false;}
    public static function isWindowHovered(flags : ImGuiFocusedFlags = 0) {return false;}
    public static function getWindowPos() : ExtDynamic<ImVec2> {return null;}
    public static function getWindowSize() : ExtDynamic<ImVec2> {return null;}
    public static function getWindowWidth() : Single {return 0;}
	public static function getWindowHeight(): Single {return 0;}
	
    public static function setNextWindowPos(pos : ExtDynamic<ImVec2>, cond : ImGuiCond = 0, pivot : ExtDynamic<ImVec2> = null) {}
    public static function setNextWindowSize(size: ExtDynamic<ImVec2>, cond : ImGuiCond = 0) {}
    public static function setNextWindowSizeConstraints(size_min : ExtDynamic<ImVec2>, size_max : ExtDynamic<ImVec2>) {}
    public static function setNextWindowContentSize(size : ExtDynamic<ImVec2>) {}
    public static function setNextWindowCollapsed(collapsed : Bool, cond : ImGuiCond = 0) {}
    public static function setNextWindowFocus() {}
    public static function setNextWindowBgAlpha(alpha : Single) {}
    public static function setWindowPos(pos : ExtDynamic<ImVec2>, cond : ImGuiCond = 0) {}
    public static function setWindowSize(size : ExtDynamic<ImVec2>, cond : ImGuiCond = 0) {}
    public static function setWindowCollapsed(collapsed : Bool, cond : ImGuiCond = 0) {}
    public static function setWindowFocus() {}
    public static function setWindowFontScale(scale : Single) {}
    public static function setWindowPos2(name : String, pos : ExtDynamic<ImVec2>, cond : ImGuiCond = 0) {}
    public static function setWindowSize2(name : String, size : ExtDynamic<ImVec2>, cond : ImGuiCond = 0) {}
    public static function setWindowCollapsed2(name : String, collapsed : Bool, cond : ImGuiCond = 0) {}
	public static function setWindowFocus2(name : String) {}

	public static function dockSpace(id : Int, size : ExtDynamic<ImVec2> = null, flags : ImGuiDockNodeFlags = 0) {}
	
	// Content region
	public static function getContentRegionMax() : ExtDynamic<ImVec2> {return null;}
    public static function getContentRegionAvail() : ExtDynamic<ImVec2> {return null;}
    public static function getWindowContentRegionMin() : ExtDynamic<ImVec2> {return null;}
    public static function getWindowContentRegionMax() : ExtDynamic<ImVec2> {return null;}
	public static function getWindowContentRegionWidth() : Single {return 0;}
	
	// Windows Scrolling
	public static function getScrollX() : Single {return 0;}
    public static function getScrollY() : Single {return 0;}
    public static function getScrollMaxX() : Single {return 0;}
    public static function getScrollMaxY() : Single {return 0;}
    public static function setScrollX(scroll_x : Single) {}
    public static function setScrollY(scroll_y : Single) {}
    public static function setScrollHereX(center_x_ratio : Single = 0.5) {}
    public static function setScrollHereY(center_y_ratio : Single = 0.5) {}
    public static function setScrollFromPosX(local_x : Single, center_x_ratio : Single = 0.5) {}
	public static function setScrollFromPosY(local_y : Single, center_y_ratio : Single = 0.5) {}	
	
	// Parameters stacks
    public static function pushStyleColor(idx : ImGuiCol, col : ImU32) {}
    public static function pushStyleColor2(idx : ImGuiCol, col : ExtDynamic<ImVec4>) {}
    public static function popStyleColor(count : Int = 1) {}
    public static function pushStyleVar(idx : ImGuiStyleVar, val : Single) {}
    public static function pushStyleVar2(idx : ImGuiStyleVar, val : ExtDynamic<ImVec2>) {}
    public static function popStyleVar(count : Int = 1) {}
    public static function getStyleColorVec4(idx : ImGuiCol) : ExtDynamic<ImVec4> {return null;}
    public static function getFontSize() : Single {return 0;}
    public static function getFontTexUvWhitePixel() : ExtDynamic<ImVec2> {return null;}
    public static function getColorU32(idx : ImGuiCol, alpha_mul : Single = 1.0) : ImU32 {return 0;}
    public static function getColorU322(col : ExtDynamic<ImVec4>) : ImU32 {return 0;}
    public static function getColorU323(col : ImU32) : ImU32 {return 0;}
    public static function pushItemWidth(item_width : Single) {}
    public static function popItemWidth() {}
    public static function setNextItemWidth(item_width : Single) {}
    public static function calcItemWidth() : Single {return 0;}
    public static function pushTextWrapPos(wrap_local_pos_x : Single = 0.0) {}
    public static function popTextWrapPos() {}
    public static function pushAllowKeyboardFocus(allow_keyboard_focus : Bool) {}
    public static function popAllowKeyboardFocus() {}
    public static function pushButtonRepeat(repeat : Bool) {}
    public static function popButtonRepeat() {}

	// Cursor / Layout
    public static function separator() {}
    public static function sameLine(offset_from_start_x : Single = 0.0, spacing : Single = -1.0) {}
    public static function newLine() {}
    public static function spacing() {}
    public static function dummy(size : ExtDynamic<ImVec2>) {}
    public static function indent(indent_w : Single = 0.0) {}
    public static function unindent(indent_w : Single = 0.0) {}
    public static function beginGroup() {}
    public static function endGroup() {}
    public static function getCursorPos() : ExtDynamic<ImVec2> {return null;}
    public static function getCursorPosX() : Single {return 0;}
    public static function getCursorPosY() : Single {return 0;}
    public static function setCursorPos(local_pos : ExtDynamic<ImVec2>) {}
    public static function setCursorPosX(local_x : Single) {}
    public static function setCursorPosY(local_y : Single) {}
    public static function getCursorStartPos() : ExtDynamic<ImVec2> {return null;}
    public static function getCursorScreenPos() : ExtDynamic<ImVec2> {return null;}
    public static function setCursorScreenPos(pos : ExtDynamic<ImVec2>) {}
    public static function alignTextToFramePadding() {}
    public static function getTextLineHeight() : Single {return 0;}
    public static function getTextLineHeightWithSpacing() : Single {return 0;}
    public static function getFrameHeight() : Single {return 0;}
	public static function getFrameHeightWithSpacing() : Single {return 0;}

	// ID stack/scopes
	public static function pushID(str_id : String) {}
    public static function pushID2(str_id_begin : String, str_id_end : String) {}
    public static function pushID3(int_id : Int) {}
    public static function popID() {}
    public static function getID(str_id : String) : Int {return 0;}
    public static function getID2(str_id_begin : String, str_id_end : String) : Int {return 0;}

    // Widgets: Text
    public static function text(text : String) {}
    public static function textColored(col : ExtDynamic<ImVec4>, fmt : String) {}
    public static function textDisabled(text : String) {}
    public static function textWrapped(text : String) {}
    public static function labelText(label : String, text : String) {}
    public static function bulletText(text : String) {}

	// Widgets: Main
	public static function button(name : String, size : ExtDynamic<ImVec2>) : Bool {return false;}
	public static function smallButton(label : String) : Bool {return false;}
    public static function invisibleButton(str_id : String, size : ExtDynamic<ImVec2>) : Bool {return false;}
    public static function arrowButton(str_id : String, dir : ImGuiDir) : Bool {return false;}
    public static function image(user_texture_id : ImTextureID, size : ExtDynamic<ImVec2>, uv0 : ExtDynamic<ImVec2> = null, uv1 : ExtDynamic<ImVec2> = null, tint_col : ExtDynamic<ImVec4> = null, border_col : ExtDynamic<ImVec4> = null) {}
    public static function imageButton(user_texture_id : ImTextureID, size : ExtDynamic<ImVec2>, uv0 : ExtDynamic<ImVec2> = null,  uv1 : ExtDynamic<ImVec2> = null, frame_padding : Int = -1, bg_col : ExtDynamic<ImVec4> = null, tint_col : ExtDynamic<ImVec4> = null) : Bool {return false;}
    public static function checkbox(label : String, v : hl.Ref<Bool>) : Bool {return false;}
    public static function checkboxFlags(label : String, flags : hl.Ref<Int>, flags_value : Int) : Bool {return false;}
    public static function radioButton(label : String, active : Bool) : Bool {return false;}
    public static function radioButton2(label : String, v : hl.Ref<Int>, v_button : Int) : Bool {return false;}
    public static function progressBar(fraction : Single, size_arg : ExtDynamic<ImVec2> = null, overlay : String = null) {}
	public static function bullet() {}

    // Widgets: Combo Box
    public static function beginCombo(label : String, preview_value : String, flags : ImGuiComboFlags = 0) : Bool {return false;}
    public static function endCombo() {}
    public static function combo(label : String, current_item : hl.Ref<Int>, items : hl.NativeArray<String>, popup_max_height_in_items : Int = -1) : Bool {return false;}
	public static function combo2(label : String, current_item : hl.Ref<Int>, items_separated_by_zeros : String, popup_max_height_in_items : Int = -1) : Bool {return false;}
	
    // Widgets: Drags
    public static function dragFloat(label : String, v : hl.NativeArray<Single>, v_speed : Single = 1.0, v_min : Single = 0.0, v_max : Single = 0.0, format : String = "%.3f", power : Single = 1.0) : Bool {return false;}
    public static function dragFloatRange2(label : String, v_current_min : hl.Ref<Single>, v_current_max : hl.Ref<Single>, v_speed : Single = 1.0, v_min : Single = 0.0, v_max : Single = 0.0, format : String = "%.3f", format_max : String = null, power : Single = 1.0) : Bool {return false;}
    public static function dragInt(label : String, v : hl.NativeArray<Int>, v_speed : Single = 1.0, v_min : Single = 0.0, v_max : Single = 0.0, format : String = "%.3f") : Bool {return false;}
	public static function dragIntRange2(label : String, v_current_min : hl.Ref<Int>, v_current_max : hl.Ref<Int>, v_speed : Single = 1.0, v_min : Single = 0.0, v_max : Single = 0.0, format : String = "%.3f", format_max : String = null) : Bool {return false;}
	
	// Widgets: Sliders
    public static function sliderFloat(label : String, v : hl.NativeArray<Single>, v_min : Single, v_max : Single, format : String = "%.3f", power : Single = 1.0) : Bool {return false;}
    public static function sliderAngle(label : String, v_rad : hl.Ref<Single>, v_degrees_min : Single = -360.0, v_degrees_max : Single = 360.0, format : String = "%.0f deg") : Bool {return false;}
    public static function sliderInt(label : String, v : hl.NativeArray<Int>, v_min : Int, v_max : Int, format : String = "%d") : Bool {return false;}
    public static function vSliderFloat(label : String, size : ExtDynamic<ImVec2>, v : hl.Ref<Single>, v_min : Single, v_max : Single, format : String = "%.3f", power : Single = 1.0) : Bool {return false;}
	public static function vSliderInt(label : String, size : ExtDynamic<ImVec2>, v : hl.Ref<Int>, v_min : Int, v_max : Int, format : String = "%d") : Bool {return false;}
	
    // Widgets: Input with Keyboard
    public static function inputText(label : String, buf : hl.Bytes, buf_size : Int, flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputTextMultiline(label : String, buf : hl.Bytes, buf_size : Int, size : ExtDynamic<ImVec2> = null, flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputTextWithHint(label : String, hint : String, buf : hl.Bytes, buf_size : Int, flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputFloat(label : String, v : hl.Ref<Single>, step : Single = 0.0, step_fast : Single = 0.0, format : String = "%.3f", flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputFloat2(label : String, v : hl.NativeArray<Single>, format : String = "%.3f", flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputFloat3(label : String, v : hl.NativeArray<Single>, format : String = "%.3f", flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputFloat4(label : String, v : hl.NativeArray<Single>, format : String = "%.3f", flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputInt(label : String, v : hl.Ref<Int>, step : Int = 1, step_fast : Int = 100, flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputInt2(label : String, v : hl.NativeArray<Int>, flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputInt3(label : String, v : hl.NativeArray<Int>, flags : ImGuiInputTextFlags = 0) : Bool {return false;}
    public static function inputInt4(label : String, v : hl.NativeArray<Int>, flags : ImGuiInputTextFlags = 0) : Bool {return false;}
	public static function inputDouble(label : String, v : hl.Ref<Float>, step : Float = 0.0, step_fast : Float = 0.0, format : String = "%.6f", flags : ImGuiInputTextFlags = 0) : Bool {return false;}
	
	// Widgets: Color Editor/Picker
    public static function colorEdit3(label : String, col : hl.NativeArray<Single>, flags : ImGuiColorEditFlags = 0) : Bool {return false;}
    public static function colorEdit4(label : String, col : hl.NativeArray<Single>,  flags : ImGuiColorEditFlags = 0) : Bool {return false;}
    public static function colorPicker3(label : String, col : hl.NativeArray<Single>, flags : ImGuiColorEditFlags = 0) : Bool {return false;}
    public static function colorPicker4(label : String, col : hl.NativeArray<Single>, flags : ImGuiColorEditFlags = 0, ref_col : hl.Ref<Single> = null) : Bool {return false;}
    public static function colorButton(desc_id : String, col : ExtDynamic<ImVec4> = null, flags : ImGuiColorEditFlags = 0, size : ExtDynamic<ImVec2> = null) : Bool {return false;}
	public static function setColorEditOptions(flags : ImGuiColorEditFlags) {}
	
	// Widgets: Trees
	public static function treeNode(label : String) : Bool {return false;}
    public static function treeNode2(str_id : String, label : String) : Bool {return false;}
    public static function treeNodeEx(label : String, flags : ImGuiTreeNodeFlags = 0) : Bool {return false;}
    public static function treeNodeEx2(str_id : String, flags : ImGuiTreeNodeFlags, label : String) : Bool {return false;}
    public static function treePush(str_id : String) {}
    public static function treePop() {}
    public static function getTreeNodeToLabelSpacing() : Single {return 0;}
    public static function collapsingHeader(label : String, flags : ImGuiTreeNodeFlags = 0) : Bool {return false;}
    public static function collapsingHeader2(label : String, p_open : hl.Ref<Bool>, flags : ImGuiTreeNodeFlags = 0) : Bool {return false;}
	public static function setNextItemOpen(is_open : Bool, cond : ImGuiCond = 0) {}
	
	// Widgets: Selectables
    public static function selectable(label : String, selected : Bool = false, flags : ImGuiSelectableFlags = 0, size : ExtDynamic<ImVec2> = null) : Bool {return false;}
	public static function selectable2(label : String, p_selected : hl.Ref<Bool>, flags : ImGuiSelectableFlags = 0, size : ExtDynamic<ImVec2> = null) : Bool {return false;}
	
    // Widgets: List Boxes
    public static function listBox(label : String, current_item : hl.Ref<Int>, items : hl.NativeArray<String>, height_in_items : Int = -1) : Bool {return false;}
    public static function listBoxHeader(label : String, size : ExtDynamic<ImVec2> = null) : Bool {return false;}
    public static function listBoxHeader2(label : String, items_count : Int, height_in_items : Int = -1) : Bool {return false;}
	public static function listBoxFooter() {}
	
	// Widgets: Data Plotting
    public static function plotLines(label : String, values : hl.NativeArray<Single>, values_offset : Int = 0, overlay_text : String = null, scale_min : Single = FLT_MAX, scale_max : Single = FLT_MAX, graph_size : ExtDynamic<ImVec2>) {}
	public static function plotHistogram(label : String, values : hl.NativeArray<Single>, values_offset : Int = 0, overlay_text : String = null, scale_min : Single = FLT_MAX, scale_max : Single = FLT_MAX, graph_size : ExtDynamic<ImVec2>) {}
	
    // Widgets: Value() Helpers.
    public static function valueBool(prefix : String, b : Bool) {}
    public static function valueInt(prefix : String, v : Int) {}
	public static function valueSingle(prefix : String, v : Single, float_format : String = null) {}
	
    // Widgets: Menus
    public static function beginMenuBar() : Bool {return false;}
    public static function endMenuBar() {}
    public static function beginMainMenuBar() : Bool {return false;}
    public static function endMainMenuBar() {}
    public static function beginMenu(label : String, enabled : Bool = true) : Bool {return false;}
    public static function endMenu() {}
    public static function menuItem(label : String, shortcut : String = null, selected : Bool = false, enabled : Bool = true) : Bool {return false;}
    public static function menuItem2(label : String, shortcut : String, p_selected : hl.Ref<Bool>, enabled : Bool = true) : Bool {return false;}
	
	// ToolTips
    public static function beginTooltip() {}
    public static function endTooltip() {}
	public static function setTooltip(fmt : String) {}
	
	// Popups
	public static function openPopup(str_id : String) {}
    public static function beginPopup(str_id : String, flags : ImGuiWindowFlags = 0) : Bool {return false;}
    public static function beginPopupContextItem(str_id : String = null, mouse_button : ImGuiMouseButton = 1) : Bool {return false;}
    public static function beginPopupContextWindow(str_id : String = null, mouse_button : ImGuiMouseButton = 1, also_over_items : Bool = true) : Bool {return false;}
    public static function beginPopupContextVoid(str_id : String = null, mouse_button : ImGuiMouseButton= 1) : Bool {return false;}
    public static function beginPopupModal(name : String, p_open : hl.Ref<Bool> = null, flags : ImGuiWindowFlags = 0) : Bool {return false;}
    public static function endPopup() {}
    public static function openPopupOnItemClick(str_id : String = null, mouse_button : ImGuiMouseButton = 1) : Void {}
    public static function isPopupOpen(str_id : String) : Bool {return false;}
	public static function closeCurrentPopup() {}
	
    // Columns
    public static function columns(count : Int = 1, id : String = null, border : Bool = true) {}
    public static function nextColumn() {}
    public static function getColumnIndex() : Int {return 0;}
    public static function getColumnWidth(column_index : Int = -1) : Single {return 0;}
    public static function setColumnWidth(column_index : Int, width : Single) {}
    public static function getColumnOffset(column_index : Int = -1) : Single {return 0;}
    public static function setColumnOffset(column_index : Int, offset_x : Single) {}
	public static function getColumnsCount() : Int {return 0;}
	
	// Tab Bars, Tabs
	public static function beginTabBar(str_id : String, flags : ImGuiTabBarFlags = 0) : Bool {return false;}
	public static function endTabBar() {}
	public static function beginTabItem(label : String, p_open : hl.Ref<Bool> = null, flags : ImGuiTabItemFlags = 0) : Bool {return false;}
	public static function endTabItem() {}
	public static function setTabItemClosed(tab_or_docked_window_label : String) {}
	
	// Logging/Capture
	public static function logToTTY(auto_open_depth : Int = -1) {}
	public static function logToFile(auto_open_depth : Int = -1, filename : String = null) {}
	public static function logToClipboard(auto_open_depth : Int = -1) {}
	public static function logFinish() {}
	public static function logButtons() {}
	public static function logText(text : String) {}
	
    // Clipping
    public static function pushClipRect(clip_rect_min : ExtDynamic<ImVec2>, clip_rect_max : ExtDynamic<ImVec2>, intersect_with_current_clip_rect : Bool) {}
    public static function popClipRect() {}

    // Focus, Activation
    public static function setItemDefaultFocus() {}
	public static function setKeyboardFocusHere(offset : Int = 0) {}
	
	// Item/Widgets Utilities
    public static function isItemHovered(flags : ImGuiHoveredFlags = 0) : Bool {return false;}
    public static function isItemActive() : Bool {return false;}
    public static function isItemFocused() : Bool {return false;}
    public static function isItemClicked(mouse_button : ImGuiMouseButton = 0) : Bool {return false;}
    public static function isItemVisible() : Bool {return false;}
    public static function isItemEdited() : Bool {return false;}
    public static function isItemActivated() : Bool {return false;}
    public static function isItemDeactivated() : Bool {return false;}
    public static function isItemDeactivatedAfterEdit() : Bool {return false;}
    public static function isItemToggledOpen() : Bool {return false;}
    public static function isAnyItemHovered() : Bool {return false;}
    public static function isAnyItemActive() : Bool {return false;}
    public static function isAnyItemFocused() : Bool {return false;}
    public static function getItemRectMin() : ExtDynamic<ImVec2> {return null;}
    public static function getItemRectMax() : ExtDynamic<ImVec2> {return null;}
    public static function getItemRectSize() : ExtDynamic<ImVec2> {return null;}
    public static function setItemAllowOverlap() {}

    // Miscellaneous Utilities
    public static function isRectVisible(size : ExtDynamic<ImVec2>) : Bool {return false;}
    public static function isRectVisible2(rect_min : ExtDynamic<ImVec2>, rect_max : ExtDynamic<ImVec2>) : Bool {return false;}
    public static function getTime() : Float {return 0;}
    public static function getFrameCount() : Int {return 0;}
	static function get_style_color_name(idx : ImGuiCol) : hl.Bytes {return null;}
    public static function getStyleColorName(idx : ImGuiCol) : String {
		return @:privateAccess String.fromUTF8(get_style_color_name(idx));
	}
    public static function calcListClipping(items_count : Int, items_height : Single, out_items_display_start : hl.Ref<Int>, out_items_display_end : hl.Ref<Int>) {}
    public static function beginChildFrame(id : ImGuiID, size : ExtDynamic<ImVec2>, flags : ImGuiWindowFlags = 0) : Bool {return false;}
	public static function endChildFrame() {}
	
	// Text Utilities
	public static function calcTextSize(text : String, text_end : String = null, hide_text_after_double_hash : Bool = false, wrap_width : Single = -1.0) : ExtDynamic<ImVec2> {return null;}

    // Color Utilities
    public static function colorConvertU32ToFloat4(color : ImU32) : ExtDynamic<ImVec4> {return null;}
    public static function colorConvertFloat4ToU32(color : ExtDynamic<ImVec4>) : ImU32 {return 0;}
    public static function colorConvertRGBtoHSV(r : Single, g : Single, b : Single, out_h : hl.Ref<Single>, out_s : hl.Ref<Single>, out_v : hl.Ref<Single>) {}
    public static function colorConvertHSVtoRGB(h : Single, s : Single, v : Single, out_r : hl.Ref<Single>, out_g : hl.Ref<Single>, out_b : hl.Ref<Single>) {}

    // Inputs Utilities: Keyboard
    public static function getKeyIndex(imgui_key : ImGuiKey) : Int {return 0;}
    public static function isKeyDown(user_key_index : Int) : Bool {return false;}
    public static function isKeyPressed(user_key_index : Int, repeat : Bool = true) : Bool {return false;}
    public static function isKeyReleased(user_key_index : Int) : Bool {return false;}
    public static function getKeyPressedAmount(key_index : Int, repeat_delay : Single, rate : Single) : Int {return 0;}
    public static function captureKeyboardFromApp(want_capture_keyboard_value : Bool = true) {}

    // Inputs Utilities: Mouse
    public static function isMouseDown(button : ImGuiMouseButton) : Bool {return false;}
    public static function isMouseClicked(button : ImGuiMouseButton, repeat : Bool = false) : Bool {return false;}
    public static function isMouseReleased(button : ImGuiMouseButton) : Bool {return false;}
    public static function isMouseDoubleClicked(button : ImGuiMouseButton) : Bool {return false;}
    public static function isMouseHoveringRect(r_min : ExtDynamic<ImVec2>, r_max : ExtDynamic<ImVec2>, clip : Bool = true) : Bool {return false;}
    public static function isMousePosValid(mouse_pos : ExtDynamic<ImVec2> = null) : Bool {return false;}
    public static function isAnyMouseDown() : Bool {return false;}
    public static function getMousePos() : ExtDynamic<ImVec2> {return null;}
    public static function getMousePosOnOpeningCurrentPopup() : ExtDynamic<ImVec2> {return null;}
    public static function isMouseDragging(button : ImGuiMouseButton, lock_threshold : Single = -1.0) : Bool {return false;}
    public static function getMouseDragDelta(button : ImGuiMouseButton = 0, lock_threshold : Single = -1.0) : ExtDynamic<ImVec2> {return null;}
    public static function resetMouseDragDelta(button : ImGuiMouseButton = 0) {}
    public static function getMouseCursor() : ImGuiMouseCursor {return 0;}
    public static function setMouseCursor(cursor_type : ImGuiMouseCursor) {}
    public static function captureMouseFromApp(want_capture_mouse_value : Bool = true) {}

    // Clipboard Utilities
	static function get_clipboard_text() : hl.Bytes {return null;}
    public static function getClipboardText() : String {
		return @:privateAccess String.fromUTF8(get_clipboard_text());
	}
    public static function setClipboardText(text : String) {}

    // Settings/.Ini Utilities
    public static function loadIniSettingsFromDisk(ini_filename : String) {}
    public static function loadIniSettingsFromMemory(ini_data : String, ini_size : Int = 0) {}
    public static function saveIniSettingsToDisk(ini_filename : String) {}
	static function save_ini_settings_to_memory(out_ini_size : hl.Ref<Int>) : hl.Bytes {return null;}
    public static function saveIniSettingsToMemory(out_ini_size : hl.Ref<Int> = null) : String {
		return @:privateAccess String.fromUTF8(save_ini_settings_to_memory(out_ini_size));
	}

	// IO
	public static function setIniFilename(filename : String) {}

	// internal functions
	public static function initialize(render_fn:Dynamic->Void) : Dynamic {return null;}
	public static function setFontTexture(texture_id : Int) {}
	public static function setKeyState(key : Int, down : Bool) {}
	public static function setSpecialKeyState(shift : Bool, ctrl : Bool, alt : Bool, super : Bool) {}
	public static function addKeyChar(c : Int) {}
	public static function setEvents(dt : Single, mouse_x : Single, mouse_y : Single, wheel : Single, left_click : Bool, right_click : Bool) {}
	public static function setDisplaySize(display_width:Int, display_height:Int) {}
	public static function wantCaptureMouse() : Bool {return false;}
	public static function wantCaptureKeyboard() : Bool {return false;}
	public static function setConfigFlags(flags:ImGuiConfigFlags = 0) : Void {}
}
