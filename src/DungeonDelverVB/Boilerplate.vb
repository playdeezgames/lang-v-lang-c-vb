Module Boilerplate
    Sub CleanUp(cleaner As Action)
        cleaner()
        If g_renderer <> IntPtr.Zero Then
            SDL_DestroyRenderer(g_renderer)
            g_renderer = IntPtr.Zero
        End If
        If g_window <> IntPtr.Zero Then
            SDL_DestroyWindow(g_window)
            g_window = IntPtr.Zero
        End If
        SDL_Quit()
    End Sub
    Function Initialize(initializer As Action) As Boolean
        If 0 <> SDL_Init(&H10F231) Then
            Return False
        End If
        Dim running As Boolean = 0 = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, g_window, g_renderer)
        If running Then
            initializer()
        End If
        Return running
    End Function
    Sub [Loop](running As Boolean, drawer As Action, updater As Func(Of Char, Boolean))
        Dim [event] As New SDL_Event
        Do
            SDL_RenderClear(g_renderer)
            SDL_RenderPresent(g_renderer)
            If SDL_WaitEvent([event]) = 1 Then
                Select Case [event].type
                    Case 256
                        Exit Do
                    Case 768
                        If Not HandleKeyDown([event].sym, updater) Then
                            Exit Do
                        End If
                End Select
            End If
        Loop
    End Sub
    ReadOnly keyTable As IReadOnlyDictionary(Of UInt32, Char) =
        New Dictionary(Of UInt32, Char) From
        {
             {SDLK_PERIOD, COMMAND_DOT},
             {SDLK_0, COMMAND_ZERO},
             {SDLK_1, COMMAND_ONE},
             {SDLK_2, COMMAND_TWO},
             {SDLK_3, COMMAND_THREE},
             {SDLK_4, COMMAND_FOUR},
             {SDLK_5, COMMAND_FIVE},
             {SDLK_6, COMMAND_SIX},
             {SDLK_7, COMMAND_SEVEN},
             {SDLK_8, COMMAND_EIGHT},
             {SDLK_9, COMMAND_NINE},
             {SDLK_DELETE, COMMAND_DOT},
             {SDLK_INSERT, COMMAND_ZERO},
             {SDLK_HOME, COMMAND_SEVEN},
             {SDLK_PAGEUP, COMMAND_NINE},
             {SDLK_END, COMMAND_ONE},
             {SDLK_PAGEDOWN, COMMAND_THREE},
             {SDLK_RIGHT, COMMAND_SIX},
             {SDLK_LEFT, COMMAND_FOUR},
             {SDLK_DOWN, COMMAND_TWO},
             {SDLK_UP, COMMAND_EIGHT},
             {SDLK_KP_1, COMMAND_ONE},
             {SDLK_KP_2, COMMAND_TWO},
             {SDLK_KP_3, COMMAND_THREE},
             {SDLK_KP_4, COMMAND_FOUR},
             {SDLK_KP_5, COMMAND_FIVE},
             {SDLK_KP_6, COMMAND_SIX},
             {SDLK_KP_7, COMMAND_SEVEN},
             {SDLK_KP_8, COMMAND_EIGHT},
             {SDLK_KP_9, COMMAND_NINE},
             {SDLK_KP_0, COMMAND_ZERO},
             {SDLK_KP_PERIOD, COMMAND_DOT}
        }
    Private Function HandleKeyDown(sym As UInteger, updater As Func(Of Char, Boolean)) As Boolean
        Dim character As Char = Char.MinValue
        If keyTable.TryGetValue(sym, character) Then
            Return updater(character)
        End If
        Return True
    End Function
End Module
