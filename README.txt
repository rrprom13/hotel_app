	The application is due to be used by hotels' administrators and they have several functions, to be described below.
	When entering the CLI, user is prompted with instructions in order to configure the hotel's parameters or read about the available helpful guides, such as "info" (read from "info.txt" - hotel's description) and "commands" (read from "commands.txt" - available services).
	In every state, regardless of the type of input to be inserted, the user can write down "exit" and close the app.
	Spaces will be trimmed from every command, at the beginning and at the end, as well as in-between, where there are more consequent spaces.

	By entering "input", the user will be prompted with the parameters to configure the hotel - number of floors and number of rooms per floor.
	After these, he / she cannot use this command anymore, as commands linked to a hotel service cannot be accessed before entering "input".

	Names will be written with capital letter and lowercase for the rest of the word - regardless the user's input.

	The classes are as follows:
		-> main.cpp - separates commands and calls their specific parser function
		-> parser.cpp - calls the functions from hotel, depending on the parameter's validation
		-> utils.cpp - parameter's validation - called from main.cpp and parser.cpp
		-> hotel.cpp - hotel's implementation
		-> floor.cpp - details regarding a floor
		-> room.cpp - a room's configuration
		-> person.cpp - used for clients

	For more information, please access "info.txt" and "commands.txt".
