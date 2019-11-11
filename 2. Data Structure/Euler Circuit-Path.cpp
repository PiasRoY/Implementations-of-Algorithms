void eulerCircuit() 
{ 
    unordered_map<int,int> edge_count; 
  
    for (int i=0; i<adj.size(); i++) { 
        edge_count[i] = adj[i].size(); 
    } 

    vector<int> circuit; 
    stack<int> curr_path; 
   
    int curr_v = 0;
    curr_path.push(0);
  
    while (!curr_path.empty()) { 
        if (edge_count[curr_v]) { 
            curr_path.push(curr_v); 
  
            int next_v = adj[curr_v].back(); 
  
            edge_count[curr_v]--; 
            adj[curr_v].pop_back(); 
  
            curr_v = next_v; 
        }  
        else { 
            circuit.push_back(curr_v); 
  
            curr_v = curr_path.top(); 
            curr_path.pop(); 
        } 
    } 

    for (int i=circuit.size()-1; i>=0; i--) { 
        cout << circuit[i]; 
        if (i) cout<<" -> "; 
    } 
}