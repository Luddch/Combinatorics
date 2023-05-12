#include <iostream>
#include <vector>
int Task13(){
    int cases5 = 0;
    for(int i =1;i<=5;i++){
        for(int j =1;j<=5;j++){
            if(j != i){
                for(int k =1;k<=5;k++){
                    if(k != j && k!= i){
                        for(int w =1;w<=5;w++){
                            if(w != k && w != j && w!= i){
                                for(int b =1;b<=5;b++){
                                    if(b != w && b != k && b != j && b!= i) {
                                        if (!( i < j && j < k || j < k && k < w || k < w && w < b || i > j && j > k || j > k && k > w || k > w && w > b)) {
                                            ++cases5;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }
    }
    return cases5;
}




void ConstructKSubsets(std::vector<std::pair<int, int>>& edgeList,int& cases, const size_t& setSize,int subsetSizeLeft,std::vector<int>& subset,int prevElementIndex = 0) {
    if (subsetSizeLeft > 0) {
        for (int i = prevElementIndex; i < setSize; i++) {
            subset.push_back(i);
            ConstructKSubsets(edgeList,cases,setSize, subsetSizeLeft - 1, subset, ++prevElementIndex);
            subset.pop_back();
        }
    } else {
        bool isPerfectMatching = true;
        std::vector<int> vertexDegreeList;
        vertexDegreeList.resize(subset.size()*2);
        for(int i =0;i<subset.size();i++){
            ++vertexDegreeList[edgeList[subset[i]].first];
            ++vertexDegreeList[edgeList[subset[i]].second];
        }
        for(int i =0;i<vertexDegreeList.size();i++){
          if(vertexDegreeList[i] != 1){
              isPerfectMatching = false;
              break;
          }
        }
        if(isPerfectMatching){
            ++cases;
        }

    }
}



int Task9B() {
    std::string labeledGraph = "CGUAAUUACGGCAUUAGCAU";
    int vertexAmount = 20;
    std::vector<std::pair<int, int>> edgeList;
    for (int i = 0; i < labeledGraph.size(); i++) {
        for (int j = 0; j < labeledGraph.size(); j++) {
            if (labeledGraph[i] == 'C' && labeledGraph[j] == 'G' || labeledGraph[i] == 'A' && labeledGraph[j] == 'U') {
                edgeList.emplace_back(i, j);
            }
        }
    }

    for(int i =0;i<edgeList.size();i++){
        if(abs(edgeList[i].first - edgeList[i].second) % 2 == 0){
             edgeList.erase(edgeList.cbegin()+i);
        }
    }
    std::vector<int> subset;
    int cases =0;
    ConstructKSubsets(edgeList,cases,edgeList.size(),vertexAmount/2,subset);
    return  cases;
}



int main() {
    std::cout << Task13() << std::endl;
    std::cout << Task9B() << std::endl;
}
