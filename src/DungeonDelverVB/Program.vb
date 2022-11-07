Module Program
	Sub Main(args As String())
		Boilerplate.Loop(
			Boilerplate.Initialize(
				AddressOf Application.Initialize),
			AddressOf Application.Draw,
			AddressOf Application.Updater)
		Boilerplate.CleanUp(AddressOf Application.CleanUp)
	End Sub
End Module
