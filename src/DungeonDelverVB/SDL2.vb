Imports System.Runtime.InteropServices

Module SDL2
    Declare Function SDL_RenderCopy Lib "SDL2.dll" (renderer As IntPtr,
                                           texture As IntPtr,
                                           srcrect As SDL_Rect,
                                           dstrect As SDL_Rect) As Integer
    Declare Sub SDL_DestroyTexture Lib "SDL2.dll" (texture As IntPtr)
    Declare Function IMG_LoadTexture Lib "SDL2_image.dll" (renderer As IntPtr, <MarshalAs(UnmanagedType.LPStr)> file As String) As IntPtr
    Declare Function SDL_RenderSetLogicalSize Lib "SDL2.dll" (renderer As IntPtr, w As Integer, h As Integer) As Integer
    Declare Function IMG_Init Lib "SDL2_image.dll" (flags As Integer) As Integer
    Declare Sub IMG_Quit Lib "SDL2_image.dll" ()
    Declare Function SDL_Init Lib "SDL2.dll" (flags As UInt32) As Integer
    Declare Function SDL_CreateWindowAndRenderer Lib "SDL2.dll" (
                                                                ByVal width As Integer,
                                                                ByVal height As Integer,
                                                                ByVal window_flags As UInt32,
                                                                ByRef window As IntPtr,
                                                                ByRef renderer As IntPtr) As Integer
    Declare Function SDL_RenderClear Lib "SDL2.dll" (ByVal renderer As IntPtr) As Integer
    Declare Function SDL_RenderPresent Lib "SDL2.dll" (ByVal renderer As IntPtr) As Integer
    Declare Sub SDL_Quit Lib "SDL2.dll" ()
    <StructLayout(LayoutKind.Explicit, Size:=56)>
    Structure SDL_Event
        <FieldOffset(0)>
        Public type As UInt32
        <FieldOffset(20)>
        Public sym As UInt32
    End Structure
    Declare Function SDL_WaitEvent Lib "SDL2.dll" (
                                                  ByRef [event] As SDL_Event) As Integer
    Declare Sub SDL_DestroyRenderer Lib "SDL2.dll" (ByVal renderer As IntPtr)
    Declare Sub SDL_DestroyWindow Lib "SDL2.dll" (ByVal window As IntPtr)
    Friend Const SDLK_PERIOD As UInt32 = 46
    Friend Const SDLK_0 As UInt32 = 48
    Friend Const SDLK_1 As UInt32 = 49
    Friend Const SDLK_2 As UInt32 = 50
    Friend Const SDLK_3 As UInt32 = 51
    Friend Const SDLK_4 As UInt32 = 52
    Friend Const SDLK_5 As UInt32 = 53
    Friend Const SDLK_6 As UInt32 = 54
    Friend Const SDLK_7 As UInt32 = 55
    Friend Const SDLK_8 As UInt32 = 56
    Friend Const SDLK_9 As UInt32 = 57
    Friend Const SDLK_DELETE As UInt32 = 127
    Friend Const SDLK_INSERT = 1073741897
    Friend Const SDLK_HOME As UInt32 = 1073741898
    Friend Const SDLK_PAGEUP As UInt32 = 1073741899
    Friend Const SDLK_END As UInt32 = 1073741901
    Friend Const SDLK_PAGEDOWN As UInt32 = 1073741902
    Friend Const SDLK_RIGHT As UInt32 = 1073741903
    Friend Const SDLK_LEFT As UInt32 = 1073741904
    Friend Const SDLK_DOWN As UInt32 = 1073741905
    Friend Const SDLK_UP As UInt32 = 1073741906
    Friend Const SDLK_KP_1 As UInt32 = 1073741913
    Friend Const SDLK_KP_2 As UInt32 = 1073741914
    Friend Const SDLK_KP_3 As UInt32 = 1073741915
    Friend Const SDLK_KP_4 As UInt32 = 1073741916
    Friend Const SDLK_KP_5 As UInt32 = 1073741917
    Friend Const SDLK_KP_6 As UInt32 = 1073741918
    Friend Const SDLK_KP_7 As UInt32 = 1073741919
    Friend Const SDLK_KP_8 As UInt32 = 1073741920
    Friend Const SDLK_KP_9 As UInt32 = 1073741921
    Friend Const SDLK_KP_0 As UInt32 = 1073741922
    Friend Const SDLK_KP_PERIOD As UInt32 = 1073741923
    Structure SDL_Rect
        Public x As Integer
        Public y As Integer
        Public w As Integer
        Public h As Integer
    End Structure
End Module
