/*
The code below doesn’t work as it’s supposed to. Fix the functions so that 
they work as the comments describe and don’t produce compiler errors or 
warnings, nor valgrind errors or memory leaks. The main function has no 
problems, and it cannot be changed. The structures are also defined correctly, 
and no includes are missing. In general, the logic of the code is correct.

The program handles map data, more specifically public transportation stops. The program 
saves them in a Map structure, that holds a location name, a TransportStop array 
The TransportStop structure holds the data for a single public transportation stop, and stores 
the name and type of the TransportStop, as well as the location (a latitude-
longitude pair) of the TransportStop.

There are six mistakes in the program, each of them clearly visible either in 
the compiler errors/warnings or valgrind output. Note that there might be more 
than one error/warning per mistake as a single mistake can create many problems 
at once.

There are two mistakes in the createStops function.
There is one mistake in the createMap function.
There is one mistake in the printStopInfo function.
There is one mistake in the freeMemory function.
*/

// ----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// public transportation stop structure holds the location
// as latitude-longitude pair, types as an enum value
// and the identifier and the name of the stop as string
typedef struct transportStop TransportStop;

/**
 * \brief Public transportation stop types are defined using a set of enum values
 * 
 */
typedef enum stopType { ALEPA_BIKE, BUS, METRO, TRAM } StopType;

/**
 * \brief Transport stop structure that is specified by location, identifier, type and 
 * name.
 * 
 */
struct transportStop {
	double location[2]; //!< The location as a latitude-longitude pair
	char identifier[6]; //!< The identifier of point of interest as a string
	StopType type;		//!< The transportation stop type
	char* name;			//!< The name of the step
};

/**
 * \brief A map structure for public tranport stop, which is composed of
 * an array of transport stops and the name of the map 
 * 
 */
typedef struct map {
	TransportStop* stops; //!< An array of transportation stops
	int stopCount;		  //!< The number of stops
	char* locationName;	  //!< The name of the map
} Map;

/**
 * \brief Create an array of public transportation stops
 * 
 * \param stopNames An array of public transportation stop names
 * \param ids An array of public transportation stop identifiers
 * \param types An array of public transportation stop types
 * \param locations An array of pairs of doubles that have the longitude-latitude pairs for each stop
 * \param stopCount The number of public transportation stops
 * \return A dynamically allocated and initialized linked-list of transport stops
 */
TransportStop* createStops(const char** stopNames,
						   const char** ids,
						   const StopType* types,
						   const double locations[][2],
						   int stopCount) {

	// Allocate memory for TransportStops
	TransportStop* stops = malloc(sizeof(TransportStop) * stopCount);

	// Go through all the given data and store it in the array
	for (int i = 0; i < stopCount; i++) {
		// Allocate memory for the stop name and copy it to the structure
		stops[i].name = malloc(sizeof(char) * (strlen(stopNames[i]) + 1));
		strcpy(stops[i].name, stopNames[i]);

		// Store the id
		strcpy(stops[i].identifier, ids[i]);

		// Store the type
		stops[i].type = types[i];

		// Store the location as lat-lon
		stops[i].location[0] = locations[i][0];
		stops[i].location[1] = locations[i][1];
	}

	return stops; // Return the created stops
}

/**
 * \brief Create a Map object from the arguments
 * 
 * \param locationName The name of the map location
 * \param stopNames An array of public transportation stop names
 * \param ids An array of public transportation stop identifiers
 * \param types An array of public transportation stop types
 * \param locations An array of pairs of doubles that have the longitude-latitude pairs for each stop
 * \param stopCount The number of public transportation stops
 * 
 * \return A dynamically allocated and initialized map object 
 */
Map* createMap(char* locationName,
			   char** stopNames,
			   char** stopIds,
			   StopType* types,
			   double locations[][2],
			   int stopCount) {

	// Allocate memory for the Map structure
	Map* map = malloc(sizeof(Map));

	// Store the location name
	map->locationName = malloc(strlen(locationName) + 1);
	strcpy(map->locationName, locationName);

	// Store the number of stops
	map->stopCount = stopCount;

	// stopNames and stopIds need to be const char **, so we need to copy them
	// to a temporary array, remember to free the memory later
	const char** stopNamesTemp = malloc(sizeof(char*) * stopCount);
	const char** stopIdsTemp = malloc(sizeof(char*) * stopCount);

	// Copy the stop names and ids to the temporary array
	for (int i = 0; i < stopCount; i++) {
		stopNamesTemp[i] = stopNames[i];
		stopIdsTemp[i] = stopIds[i];
	}

	// Create the array of transport stops
	map->stops = createStops(stopNamesTemp, stopIdsTemp, types, locations, stopCount);

	// Free the memory allocated for the temporary arrays
	free(stopNamesTemp);
	free(stopIdsTemp);

	return map;
}

/**
 * \brief Returns a human-readable string for the public transportation stop type
 * 
 * \param type The stop type
 * \return The human readable string of the stop type
 */
const char* getTypeName(StopType type) {
	switch(type) {
	case ALEPA_BIKE:
		return "alepa bike";
	case BUS:
		return "bus";
	case METRO:
		return "metro";
	case TRAM:
		return "tram";
	default:
		return "invalid type";
	}
}

/**
 * \brief Prints the content of a Map object 
 * 
 * \details This function prints the content of a Map object in the following
 *          format:
 * 
 *          <place name> has the following public transportation stops:
 *          Stop <name>, ID <identifier> at (latitude, longitude) of type <type>.
 *          ...
 * 
 * \param map The map object to be printed
 */
void printStopInfo(Map* map) {
	// Print the location name
	printf("%s has the following public transportation stops:\n",
		   map->locationName);

	// Loop through the stops and print their info
	for(int i = 0; i < map->stopCount; i++) {
		printf("Stop %s, ID %s at (%f, %f) of type %s.\n",
			   map->stops[i].name,
			   map->stops[i].identifier,
			   map->stops[i].location[0],
			   map->stops[i].location[1],
			   getTypeName(map->stops[i].type));
	}
}

/**
 * \brief Frees the dynamically allocated memory for a map object
 * 
 * \param map The object to be freed
 */
void freeMemory(Map* map) {
	// Free memory used by the names
	for(int i = 0; i < map->stopCount; i++) {
		free(map->stops[i].name);
	}

	// Free the memory used by the stops array
	free(map->stops);

	// Free the memory used by the location name
	free(map->locationName);

	// Finally free the memory used by the map itself
	free(map);
}

/**
 * \brief Main function of the program
 * 
 * \return Returns 0
 */
int main() {
	// Original data for the public transportation stops:
	// Names
	char* names[] = {"Aalto-yliopiston metroasema",
					 "Aalto-yliopisto (M)",
					 "Aalto-yliopisto (M), Korkeakoulunaukio",
					 "Aalto-yliopisto (M), Tietotie",
					 "Jämeräntaival",
					 "Teekkarikylä",
					 "Otaranta"};

	char* identifiers[] =
		{"OTA", "E2230", "541", "539", "547", "E2228", "null"};

	StopType types[] =
		{METRO, BUS, ALEPA_BIKE, ALEPA_BIKE, ALEPA_BIKE, BUS, TRAM};

	// public transportation stop location, a latitude-longitude pair
	double locations[][2] = {{60.18448, 24.82358},
							 {60.18369, 24.82812},
							 {60.18431, 24.82666},
							 {60.18498, 24.82013},
							 {60.18812, 24.83505},
							 {60.18743, 24.83388},
							 {60.18021, 24.83468}};

	// Create a map structure based on the data
	Map* map = createMap("Otaniemi", names, identifiers, types, locations, 7);

	// Print map tiles information
	printStopInfo(map);

	// Free the reserved memory
	freeMemory(map);

	return 0;
}
