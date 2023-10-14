

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>  // For INT_MAX

using namespace std;
//--------------functions to find hamiltion circuit-----------------

bool is_valid(int** graph, int num_vertices, int* path, int indx, int path_weight, int min_weight) {
    
    // Checking if path weight exceeds the min_weight found in adjacency matrix
    //and returning false so it dont have to check the path afterwards
    if (path_weight >= min_weight) {
        return false;
    }
    // Checking if the last vertex in the path has an edge to the first vertex in adjacency matrix
    if (indx == num_vertices && graph[path[indx - 1]][path[0]] > 0) {
        return true;
    }
    // Check if there is an edge between the last vertex and the next candidate vertex
    if (indx > 0 && graph[path[indx - 1]][path[indx]] == 0) {
        return false;
    }
    // Check if the candidate vertex has already been included in the path
    for (int i = 0; i < indx; i++) {
        if (path[i] == path[indx]) {
            return false;
        }
    }
    return true;
}





bool flag = false;
void backtrack_algo(int** graph, int num_vertices, int* path, int indx, int path_weight, int& min_weight,int * time,int total_time,int &c_weight,char *&characters) {
  
    int circuit_weight = path_weight + graph[path[indx - 1]][path[0]] + time[path[0]];
    
    if (indx == num_vertices) {
        // Check if the last vertex has an edge to the first vertex
        if (graph[path[indx - 1]][path[0]] > 0) {
            // Update the minimum weight found
            min_weight = min(min_weight, circuit_weight);
            // Print the Hamiltonian circuit and its weight
      
            if (circuit_weight > total_time) {
               
                if(flag==false)
                c_weight = circuit_weight;


            }
            else 
            {
                c_weight = circuit_weight;
                if (min_weight < total_time) {
                    cout << "Hamiltonian circuit found: ";
                    for (int i = 0; i < num_vertices; i++)
                    {
                        cout << path[i] << " ";
                    }
                    
                    flag = true;
                    cout << path[0] << endl;  // Include the starting vertex to complete the circuit
                    cout << "circuit in characters:     ";
                    for (int i = 0; i < num_vertices; i++)
                    {
                        for (int k = 0; k < num_vertices; k++)
                            if (path[i] == k)
                                cout << characters[k] << ",";
                        
                    }

                    cout << "h\nWeight: " << circuit_weight << endl;
                }
            }
      
        }
       return;
        

    }
  

    for (int i = 1; i < num_vertices; i++) {  // Start from vertex 1, assuming 0-indxing
        path[indx] = i;
        if (is_valid(graph, num_vertices, path, indx, path_weight, min_weight)) {
            // Update the path weight and continue the search
            int new_path_weight = path_weight + graph[path[indx - 1]][i]+time[i];
            backtrack_algo(graph, num_vertices, path, indx + 1, new_path_weight, min_weight,time,total_time,c_weight,characters);
        }
        path[indx] = -1;  // Reset the path
    }

    
}












//--------------------------MAIN----------------------------------

int main() {
    // Open the input file
    string text = ".txt";
    for (int l = 1; l <= 4; l++) 
    {
        cout << "\n\n\n\n";
     
        string file_path = "C:\\Users\\Usman's PC\\source\\repos\\algo_Project\\algo_Project\\P2_test" + to_string(l) + text;
        cout << file_path;

        cout << "\n-------------------------------------test case: " << l <<  "------------------------------------" << endl;
        
        ifstream input_file(file_path);
        if (!input_file.is_open()) {
            cout << "Failed to open the input file!" << endl;
            return 1;
        }

        // -------------------Read the number of vertices-----------------------------
        string line;
        getline(input_file, line);

        int i = 0;
        int count_vertices = 1; // to count vertices intializing it from 1 cause there will be n-1 commas and n vertices 

        while (line[i] != '}')
        {
            if (line[i] == ',')//counting vertices when a comma founded 
                count_vertices++;

            i++;
        }
        cout << "total vertices: " << count_vertices << endl;
        char* characters = new char[count_vertices];//to store vertices names
        i = 0;
        int char_count = 0;

        //-------------------vertices_names---------------------------------
        while (line[i] != '}')
        {

            if (line[i] == ',')//storing vertices names  when a comma founded used line[i-1] cause vertex name will be before comma :)
            {
                characters[char_count] = line[i - 1];
                char_count++;

                if (line[i + 2] == '}')
                    characters[char_count] = line[i + 1];
            }

            i++;

        }

        //vertices names
        cout << "vertices={ ";
        for (int i = 0; i < count_vertices; i++)
            cout <<  characters[i] << ",";
        cout << " }\n";

        int num_vertices = count_vertices;
        //-----------------edges------------------
        getline(input_file, line);
        //cout << line; // edges line

        // storing wieghts characters in adjacency matrix
        int size_w = 1;//to count EDGES intializing it from 1 cause there will be n-1 commas and max n edges
        int count_w = 0;


        i = 0;
        while (line[i] != '}')
        {
            if (line[i] == ',')//counting commas for size of weight array
                size_w++;

            i++;
        }

        //    cout << "size: " << size_w;
        char* weights_char = new char[size_w]; // to store weights

        i = 0;
        while (line[i] != '}')
        {

            if (line[i] == '(' && line[i + 2] == ',')//storing vertices names  when a comma founded used line[i-1] cause vertex name will be before comma :)
            {
                weights_char[count_w] = line[i + 1];
                count_w++;

                if (line[i + 4] == ')')
                {
                    weights_char[count_w] = line[i + 3];
                    count_w++;
                }
            }

            i++;

        }

        cout << "Weights characters={ ";
        for (int i = 0; i < size_w; i++)
            cout << weights_char[i] << ",";
        cout << "}" << endl;


        //------------------------edges_weights------------------
        getline(input_file, line);
        cout << line;
        int* weights_int = new int[size_w / 2];
        int count_w_int = 0;
        i = 0; int k = 0;
        string st="";

        while (line[i] != '}')//storing edges weight  when a comma founded used line[i-1] cause edges weight will be before comma :)
        {
            if (line[i] == '{')
            {
                while (line[k] != '}') {
                    weights_int[count_w_int] = line[i];


                    k = i + 1;

                    while (line[k] != ',')
                    {
                        st += line[k];
                        k++;
                        if (line[k] == ',')
                        {
                            i = k;
                            break;
                        }

                        if (line[k] == '}')
                            break;
                    }

                    weights_int[count_w_int] = stoi(st);
                    st = "\0";
                    //    cout << time_int[time_char_count];
                    count_w_int++;
                }
            }

            i++;

        }

        cout << "weightssssssssssssssssssssss: ";
        


        //while (line[i] != '}')
        //{
        //   
        //   
        //    if (line[i] == ',')//storing edges weight  when a comma founded used line[i-1] cause edges weight will be before comma :)
        //    {
        //        
        //        weights_int[count_w_int] = line[i - 1] - 48;
        //        count_w_int++;

        //        if (line[i + 2] == '}')
        //            weights_int[count_w_int] = line[i + 1] - 48;
        //    }

        //    i++;

        //}

        cout << "weights={ ";
        for (int i = 0; i < size_w / 2; i++)
            cout << weights_int[i] << ",";
        cout << " }" << endl;




        int* arr = new int[size_w];//storing vetrices indexes


        int** weighted_arr = new int* [size_w / 2];//for storing edges vertices index at 1 and 2 and weights at 3
        for (int i = 0; i < size_w / 2; i++)
            weighted_arr[i] = new int[3];

     //   cout << "\narray:\n";
        //----------------------for just getting vertices numbers in int for weighted_array-------------------------
        for (int i = 0; i < size_w; i++)
        {
            for (int k = 0; k < count_vertices; k++)
            {
                if (weights_char[i] == characters[k])
                    arr[i] = k;
            }
      //      cout << arr[i] << ",";
        //    cout << endl;
        }

        int i2 = 0;
        //--------------//for storing edges vertices index at 1 and 2 and weights at 3
        for (int i = 0; i < size_w / 2; i++)
        {
            // for (int j = 0; j < size_w; j++) {
            if (i2 % 2 == 0) {
                weighted_arr[i][0] = arr[i2];
                i2++;
            }
            if (i2 % 2 == 1)
            {
                weighted_arr[i][1] = arr[i2];
                i2++;
            }
        }
        //----------------stroing weights in 3rd index of weighted array----------------------
        for (int i = 0; i < size_w / 2; i++)
        {
            // for (int j = 0; j < size_w; j++) {
            weighted_arr[i][2] = weights_int[i];
        }


        //----------------for checking ouptut of wrighted array-------------------- just for myself
/*        for (int i = 0; i < size_w / 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << weighted_arr[i][j] << ",";
            }
            cout << endl;
        }
        */


        //---------------------------------------------------------Adjacency MATRIX------------------------
            // Initialize the adjacency matrix
        int** adjacency_matrix = new int* [num_vertices];
        for (int i = 0; i < num_vertices; i++)
            adjacency_matrix[i] = new int[num_vertices];

        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                adjacency_matrix[i][j] = 0;
            }
        }


        int v1 = 0, v2 = 0, w = 0;
        bool row_flag = false;
        bool col_flag = false;



        for (int i = 0; i < size_w / 2; i++)
        {
            v1 = weighted_arr[i][0];
            v2 = weighted_arr[i][1];
            adjacency_matrix[v1][v2] = weighted_arr[i][2];
            adjacency_matrix[v2][v1] = weighted_arr[i][2];

        }




        // Print the adjacency matrix
        cout << "Adjacency matrix:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                cout << adjacency_matrix[i][j] << " ";
            }
            cout << endl;
        }

        getline(input_file, line);
        cout << line;

        char* time_char = new char[num_vertices];
        time_char[0] = 'h';
        int time_char_count = 1;

        int* time_int = new int[num_vertices];
        time_int[0] = 0;
        string s;
        i = 0;

        int j = 0;
        while (line[i] != '\0')
        {
            if (line[i + 1] == ')')
            {
                time_char[time_char_count] = line[i];

                if (line[i + 2] == '=')
                {

                    j = i + 3;

                    while (line[j] != ',')
                    {
                        s += line[j];
                        j++;
                        if (line[j] == ',')
                        {
                            i = j;
                            break;
                        }

                        if (line[j] == '\0')
                            break;
                    }
                }
                time_int[time_char_count] = stoi(s);
                s = "\0";
                //    cout << time_int[time_char_count];
                time_char_count++;

            }

            i++;

        }

        //to see times storing corrrectly
/*        for (int i = 0; i < num_vertices; i++)
            cout << "\nchar " << time_char[i] << ": " << time_int[i];
       */


        int* path = new int[num_vertices];
        for (int i = 0; i < num_vertices; i++)
            path[i] = -1;  // Initialize with -1

        path[0] = 0;  // Start from vertex 0, assuming 0-indexing

        //storing times 
        int* time = new int[num_vertices];

        for (int i = 0; i < num_vertices; i++)
        {
            for (int k = 0; k < num_vertices; k++) {
                if (time_char[i] == characters[k])
                {
                    time[k] = time_int[i];
                }
            }

        }


        getline(input_file, line);
        //cout << line;
    //------------reading total time----------------------------        
        int total_time = 0;
        s = "";
        i = 0;
        for (i = 0; line[i] != '\0'; i++)
        {
            if (line[i] >= '0' && line[i] <= '9')
                s += line[i];
        }
        total_time = stoi(s);

        cout << "\ntotal_time: T= " << total_time << endl;

        int min_weight = INT_MAX;
        int c_weight = 0;

        backtrack_algo(adjacency_matrix, num_vertices, path, 1, time[0], min_weight, time, total_time, c_weight, characters);
        if (c_weight > total_time)
            cout << "no feasible circuit\n";
        else
            cout << "Shortest Hamiltonian circuit weight: " << min_weight << endl << endl << endl;


        /*   for (int i = 0; i < num_vertices; i++)
           {
               for (int k = 0; k < num_vertices; k++)
               {
                   if (characters[k] == time_char[i])
                       cout << time_char[k] <<",";
               }
           }
        */   // Close the input file
        input_file.close();
    }
    return 0;
}
