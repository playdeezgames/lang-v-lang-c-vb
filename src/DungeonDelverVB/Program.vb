Imports System.Runtime.InteropServices
Module Program
    Const SCREEN_WIDTH = 1280
    Const SCREEN_HEIGHT = 720
    Const COMMAND_ZERO = "0"c
    Const COMMAND_ONE = "1"c
    Const COMMAND_TWO = "2"c
    Const COMMAND_THREE = "3"c
    Const COMMAND_FOUR = "4"c
    Const COMMAND_FIVE = "5"c
    Const COMMAND_SIX = "6"c
    Const COMMAND_SEVEN = "7"c
    Const COMMAND_EIGHT = "8"c
    Const COMMAND_NINE = "9"c
    Const COMMAND_DOT = "."c
    Sub Main(args As String())
        If SDL_Init(&H10F231) = 0 Then
            Dim window As IntPtr = IntPtr.Zero
            Dim renderer As IntPtr = IntPtr.Zero
            If SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, window, renderer) = 0 Then
                Dim [event] As New SDL_Event
                Do
                    SDL_RenderClear(renderer)
                    SDL_RenderPresent(renderer)
                    If SDL_WaitEvent([event]) = 1 Then
                        Select Case [event].type
                            Case 256
                                Exit Do
                            Case 768
                                If Not HandleKeyDown([event].sym) Then
                                    Exit Do
                                End If
                        End Select
                    End If
                Loop
                If renderer <> IntPtr.Zero Then
                    SDL_DestroyRenderer(renderer)
                    renderer = IntPtr.Zero
                End If
                If window <> IntPtr.Zero Then
                    SDL_DestroyWindow(window)
                    window = IntPtr.Zero
                End If
            End If
            SDL_Quit()
        End If
    End Sub
    ReadOnly keyTable As IReadOnlyDictionary(Of UInt32, Char) =
        New Dictionary(Of UInt32, Char) From
        {
             {SDLK_PERIOD, "."c},
             {SDLK_0, "0"c},
             {SDLK_1, "1"c},
             {SDLK_2, "2"c},
             {SDLK_3, "3"c},
             {SDLK_4, "4"c},
             {SDLK_5, "5"c},
             {SDLK_6, "6"c},
             {SDLK_7, "7"c},
             {SDLK_8, "8"c},
             {SDLK_9, "9"c},
             {SDLK_DELETE, "."c},
             {SDLK_INSERT, "0"c},
             {SDLK_HOME, "7"c},
             {SDLK_PAGEUP, "9"c},
             {SDLK_END, "1"c},
             {SDLK_PAGEDOWN, "3"c},
             {SDLK_RIGHT, "6"c},
             {SDLK_LEFT, "4"c},
             {SDLK_DOWN, "2"c},
             {SDLK_UP, "8"c},
             {SDLK_KP_1, "1"c},
             {SDLK_KP_2, "2"c},
             {SDLK_KP_3, "3"c},
             {SDLK_KP_4, "4"c},
             {SDLK_KP_5, "5"c},
             {SDLK_KP_6, "6"c},
             {SDLK_KP_7, "7"c},
             {SDLK_KP_8, "8"c},
             {SDLK_KP_9, "9"c},
             {SDLK_KP_0, "0"c},
             {SDLK_KP_PERIOD, "."c}
        }
    Private Function HandleKeyDown(sym As UInteger) As Boolean
        Dim character As Char = Char.MinValue
        If keyTable.TryGetValue(sym, character) Then
            Return HandleCommand(character)
        End If
        Return True
    End Function

    Private Function HandleCommand(command As Char) As Boolean
        Return True
    End Function
End Module
