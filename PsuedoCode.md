FUNCTION BACKTRACK_ALGO(GRAPH, NUM_VERTICES, PATH, INDX, PATH_WEIGHT, MIN_WEIGHT, TIME, TOTAL_TIME, C_WEIGHT, CHARACTERS)
o // Compute circuit weight
o CIRCUIT_WEIGHT = PATH_WEIGHT + GRAPH[PATH[INDX-1]][PATH[0]] + TIME[PATH[0]]
o // Check if all vertices have been included in the path
o IF INDX == NUM_VERTICES THEN
o // Check if the last vertex has an edge to the first vertex
o IF GRAPH[PATH[INDX-1]][PATH[0]] > 0 THEN
o // Update minimum weight found
o MIN_WEIGHT = MIN(MIN_WEIGHT, CIRCUIT_WEIGHT)
o // Check if circuit weight exceeds total time allowed
o IF CIRCUIT_WEIGHT > TOTAL_TIME THEN
o // Update current weight if first time exceeding total time
o IF FLAG == FALSE THEN
 C_WEIGHT = CIRCUIT_WEIGHT
o END IF
o ELSE
o C_WEIGHT = CIRCUIT_WEIGHT
o // Print Hamiltonian circuit and its weight
o IF MIN_WEIGHT < TOTAL_TIME THEN
o PRINT("HAMILTONIAN CIRCUIT FOUND:")
o FOR I = 0 TO NUM_VERTICES-1 DO
o PRINT(PATH[I])
o END FOR
o FLAG = TRUE
o PRINT(PATH[0])
o PRINT("CIRCUIT IN CHARACTERS:")
o FOR I = 0 TO NUM_VERTICES-1 DO
o FOR K = 0 TO NUM_VERTICES-1 DO

o IF PATH[I] == K THEN
o PRINT(CHARACTERS[K])
o END IF
o END FOR
o END FOR
o PRINT("H")
o PRINT("WEIGHT:", CIRCUIT_WEIGHT)
o END IF
o END IF
o END IF
o RETURN
o END IF
o // Try all possible candidate vertices
o FOR I = 1 TO NUM_VERTICES-1 DO
o PATH[INDX] = I
o // Check if the candidate vertex is valid
o IF IS_VALID(GRAPH, NUM_VERTICES, PATH, INDX, PATH_WEIGHT, MIN_WEIGHT) THEN
o // Update path weight and continue the search
o NEW_PATH_WEIGHT = PATH_WEIGHT + GRAPH[PATH[INDX-1]][I] + TIME[I]
o BACKTRACK_ALGO(GRAPH, NUM_VERTICES, PATH, INDX+1, NEW_PATH_WEIGHT, MIN_WEIGHT, TIME, TOTAL_TIME, C_WEIGHT, CHARACTERS)
o END
