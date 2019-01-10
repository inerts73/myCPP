#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

std::vector<int> myVector = {1,2,3};
const int rMax = myVector.size();
struct History 
{
    std::vector<int> v;
    
    History(int vSize)
    {
      for (int i=0;i<vSize;i++)
      {
        v.push_back(0);  
      };
    };
};
struct History history(rMax);
std::vector<History> resultVector;

void displayVector(std::vector<History> const &hVector)
{
    for_each(hVector.begin(), hVector.end(), 
             [](History h)
             {
                 for (int i=0;i<rMax;i++)
                 {
                    if (i == 0 && i == rMax - 1){
                        std::cout << "(" << h.v[i] << ")";
                        continue;
                    } 
                    if (i == 0) {
                        std::cout << "(" << h.v[i];
                        continue;
                    }
                    if (i > 0 && i < rMax - 1){
                        std::cout << "," << h.v[i]; 
                        continue;
                    }
                    if (i == rMax-1) {
                        std::cout << "," << h.v[i] << ")";
                    }
                 }
                 std::cout << " ";
             });
     std::cout << std::endl;
};

bool checkIfExists(History h, std::vector<History> const &hVector)
{
    for (int i=0;i<hVector.size();i++)
    {
        if (h.v == hVector[i].v)
        {
            return true;    
        };
    };
    return false;
};

void getVector(std::vector<int> const &nVector, int const &r)
{
    if (r == 0) 
    {
        struct History component = history; 
        // std::sort(component.v.begin(), component.v.begin() + rMax);
        if (checkIfExists(component, resultVector) == false)
        {
            resultVector.push_back(component);    
        };
        return;
    };
    
    for (int i=0;i<nVector.size();i++)
    {
        history.v[r-1] = nVector[i];
        std::vector<int> popedVector = nVector;
        popedVector.erase(popedVector.begin() + i);
        getVector(popedVector, r-1);
    };
    
};

int main(void){
    getVector(myVector,rMax);
    std::sort(resultVector.begin(), resultVector.end(), [](History h1, History h2){return (h1.v[0] < h2.v[0]);});
    std::cout << "Printing " << resultVector.size() << " permutations =>" << std::endl;
    displayVector(resultVector);
}