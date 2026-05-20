to reconstruct the initial data do:

excract all data related to the physics
`python3 recursive_extract.py dump.c CTrackManiaRace::Validate`

split the physics data into files in the src dir
`python3 split_classes.py`

reconstruct the structs based on the calls of the source files
`python3 reconstruct_structs.py src`

split the structs into files in the include directory
`python3 split_structs.py`