Module Application
    Friend g_texture As IntPtr = IntPtr.Zero
    Friend Sub Initialize()
        SDL_RenderSetLogicalSize(g_renderer, SCREEN_WIDTH \ 2, SCREEN_HEIGHT \ 2)
        IMG_Init(2)
        g_texture = IMG_LoadTexture(g_renderer, "romfont8x8.png")
    End Sub
    Friend Sub Draw()
        Dim dst As New SDL_Rect() With {.x = 0, .y = 0, .w = 16, .h = 16}
        Dim src As New SDL_Rect() With {.x = 32, .y = 0, .w = 16, .h = 16}
        SDL_RenderCopy(g_renderer, g_texture, src, dst)
    End Sub
    Friend Sub CleanUp()
        IMG_Quit()
        If g_texture <> IntPtr.Zero Then
            SDL_DestroyTexture(g_texture)
            g_texture = IntPtr.Zero
        End If
    End Sub

    Friend Function Updater(command As Char) As Boolean
        Return command <> "."c
    End Function
End Module
