//
//  main.cpp
//  prim
//
//  Created by mike on 16/9/28.
//  Copyright © 2016年 ws190. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#define max_float 10000.0;//the max float


void prim(float **weight_of_path,int num_of_vertices)//use prim to get the mst
{
    int nearst[num_of_vertices];//store the nearst node
    float mindist[num_of_vertices];//store the mindist
    int end_node=1;
    for(int i=1;i<num_of_vertices;i++)//start from node 1 all nearst set to 1 mindist equal to
    {
        nearst[i]=1;
        mindist[i]=weight_of_path[0][i];
    }

    
    
    int start_node=0;
    int mark=0;// a mark to check if the value have been change from the first time sort, to check connect to node one or not
    int first_time_mark=0;
    float total_value_path=0;
    for(int i=1;i<num_of_vertices;i++)//repeat n-1 times
    {
        float min= max_float;//set min to max
        for(int j=1;j<num_of_vertices;j++)//find the min value of mindist
        {
            if(mindist[j]>0&&mindist[j]<=min)
            {
                min=mindist[j];
                start_node=j;
            }
        }
        if(first_time_mark==0)
        {
            cout<<"using the prim, the result is : "<<endl;
            cout<<1<<" -> "<<start_node+1<<endl;
            first_time_mark=1;
        }
        total_value_path+=min;
        mindist[start_node]=-1;//the node already selected drop it
        
        for(int j=1;j<num_of_vertices;j++)// to find if there's new node connected to the last picked node less than the value in mindist
        {
            
            if(weight_of_path[j][start_node]<mindist[j])
            {
                mindist[j]=weight_of_path[j][start_node];// put new smallest value in the minist
                end_node=j+1;
                mark=1;//it is not the node connected to node one

            }
        
        }
        if(mark==1&&start_node+1!=end_node)//if node connect to the node one, the value have been changed form the first time sort, it will be a new node
        cout<<start_node+1<<" -> "<<end_node<<endl;
        if(mark==0&&start_node+1!=end_node)//if connect to node one, the end node will be node one
        cout<<start_node+1<<" -> "<<1<<endl;
        
        mark=0;
    }
    cout<<"the total of the weight is : "<<total_value_path<<endl;
}
void readfile()
{
    //read the file
    fstream ins;
    ins.open("input1.txt");
    if(!ins.good())//if cant open break
    {
        cout<<"wrong file name"<<endl;
    }
    int num_of_vertices;
    ins>>num_of_vertices;//read the number of vertices in the array
    //float weight_of_path[num_of_vertices][num_of_vertices];
    
    
    float** weight_of_path = new float* [num_of_vertices];//the array store all the weight of the nodes
    for (int i = 0; i < num_of_vertices; i++)//init the array
        weight_of_path[i] = new float[num_of_vertices];
    
    
    
    for(int i=0;i<num_of_vertices;i++)//read in all the weight between the nodes store in the array
    {
        for(int j=0;j<num_of_vertices;j++)
        {
            ins>>weight_of_path[i][j];
//            cout<<weight_of_path[i][j]<<" ";
        }
    }
    prim(weight_of_path,num_of_vertices);
    
}

int main(int argc, const char * argv[]) {
    readfile();
    return 0;
}
 
