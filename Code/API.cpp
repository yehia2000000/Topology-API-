#include <iostream>
#include <fstream>
#include "Classes.cpp"

int GetNumberofComponent (string FileNme); // this function used to get the number of component from file
int GetNumberofTerminal (string FileName , int position); //this function used to get the number if terminal device 
void ReadTopology (component *Copy_Object , string FileName, int Numberofcomponent); // this function  used to read the information from file to memory
void WriteToplogy (component *Copy_Object , string FileName,int NumberOfComponent); // create or overwrite the the topolpgy from the memory to file
void DeleteTopology (Topolgy *Copy_top); // delete the topology from the memory 
void QueryDevice (component *Copy_Object , string DeviceName); // get the information of the component 
string QueryNetlist (component *Copy_Object,int NumberComponent , string TerminalName1_1,string TerminalName2_2,string TerminalName3_3,string TerminalConn1_1,string TerminalConn2_2,string TerminalConn3_3); // Get the device that has the same argument Feature of the netlist 
string ExtractString (string BaseString, int FirstIndex, int EndIndex); // this function that used to extract the sequenence of character from the base string  



int main ()
{
    /*
    this cell is initialization of the test 

    */
    string min ,max , defaultt ;
    string TerminalNam1 , TerminalNam2 , TerminalNam3 ;
    string TerminalConn1,TerminalConn2 ,TerminalConn3 ;

    string FileName="topology.json";
    int NumberOfComponent ; 
    NumberOfComponent = GetNumberofComponent(FileName);
    Topolgy *T1 ;
    component object [NumberOfComponent];
    T1 = object;
    ReadTopology (object,FileName ,NumberOfComponent);
        WriteToplogy (object , "file.json" ,NumberOfComponent);

/***********************************************************************************************************/
/***********************************************************************************************************/
/*
- this part iw will check the delete and Write function Function so, i read the topology from file and save it in memory 
and delete it and try to display the any parameter of component
- i write the topology in New File if it not exist 
- if file -->exist i overwrite File 

*/
    /*
    ReadTopology (object,FileName ,NumberOfComponent);
    DeleteTopology (T1);
    cout<<object[0].Type_voidComponentGetType();
    WriteToplogy (object , "file.json" ,NumberOfComponent);
    */
/***********************************************************************************************************/
/***********************************************************************************************************/
/*
this part test the Read Functin and try to display the Feature

*/
    /*
    ReadTopology (object,FileName ,NumberOfComponent);
    
    cout<<"Topology id of component 1 :"<<object[0].Toplogy_voidGetId()<<endl;
    cout<<"Topology id of component 2 :"<<object[1].Toplogy_voidGetId()<<endl;

    cout<<"Component 1 type "<<object[0].Type_voidComponentGetType()<<endl;
    cout<<"Component 2 type "<<object[1].Type_voidComponentGetType()<<endl;

    cout<<"Component 1 id "<<object[0].Type_voidComponentGetId()<<endl;
    cout<<"Component 2 id "<<object[1].Type_voidComponentGetId()<<endl;

    cout << "the tolarance of componet 1 : "<<endl;
    object[0].Type_voidComponentGetTolarance( &defaultt,&min,&max );
    cout<<"The default Value :"<<defaultt <<endl ;
    cout<<"The Min Value :"<<min <<endl ;
    cout<<"The Max Value :"<<max <<endl ;


    cout << "the tolarance of componet 2 : "<<endl;
    object[1].Type_voidComponentGetTolarance( &defaultt,&min,&max );
    cout<<"The default Value :"<<defaultt <<endl ;
    cout<<"The Min Value :"<<min <<endl ;
    cout<<"The Max Value :"<<max <<endl ;

    cout << "Netlist of component 1 :"<<endl; 
    TerminalNam1 , TerminalNam2 , TerminalNam2 ;
    TerminalConn1,TerminalConn2 ,TerminalConn3 ;    
    object[0].Type_voidComponentGetNetlist(&TerminalNam1,&TerminalNam2,&TerminalConn1,&TerminalConn2);
    cout<<"Terminal 1 (Component1) :"<<TerminalNam1<< "connect to "<<TerminalConn1 <<endl ;
    cout<<"Terminal 2 (Component1) :"<<TerminalNam2<< "connect to "<<TerminalConn2 <<endl ;
    object[1].Type_voidComponentGetNetlist(&TerminalNam1,&TerminalNam2,&TerminalNam3,&TerminalConn1,&TerminalConn2,&TerminalConn3);
    cout<<"Terminal 1 (Component2):"<<TerminalNam1<< "connect to "<<TerminalConn1 <<endl ;
    cout<<"Terminal 2 (Component2):"<<TerminalNam2<< "connect to "<<TerminalConn2 <<endl ;
    cout<<"Terminal 3 (Component2):"<<TerminalNam3<< "connect to "<<TerminalConn3 <<endl ;

    */
/***********************************************************************************************************/
/***********************************************************************************************************/
/*

this Part to test the QueryNetlist

*/
/*
    object[0].Type_voidComponentGetNetlist(&TerminalNam1,&TerminalNam2,&TerminalConn1,&TerminalConn2);
    cout<<"Terminal 2 (Component1) :"<<TerminalNam2<< "connect to "<<TerminalConn2 <<endl ;
    defaultt= QueryNetlist(object,NumberOfComponent ,"\"t1\"" ,"\"t2\"","","\"vdd\"","\"n1\"","");
    cout<<defaultt;
*/
    return 0 ; 
}


int GetNumberofTerminal (string FileName , int position )
{
    int Counter  =1 ;
    int Found ;
    string line ;
    ifstream fin ; 
    fin.open(FileName) ;

    fin.seekg(position);
    while (fin)
    {
        getline(fin,line);
        Found = line.find ("\"netlist\": ");
        if (Found !=string::npos)
        {
            while (fin)
            {
                getline(fin,line);
                Found = line.find(',');
                if (Found != string::npos)
                {
                    Counter++;
                }
                Found = line.find('}');
                if (Found != string::npos)
                {
                    break;
                }
            }
            return Counter ; 
        }
    }
return 0 ;

}

string ExtractString (string BaseString, int FirstIndex, int EndIndex)
{
    string ExtractString = "" ;
    if(EndIndex < BaseString.length())
    {
        for (int i=FirstIndex ; i<=EndIndex;i++)
        {
            ExtractString = ExtractString + BaseString[i];

        }
        return ExtractString ;
    }
    else 
    {
        return "Error Index";
    }



}


int GetNumberofComponent (string FileNme)
{
    string line ;
    int Found;

    int NubmberOfComponent =0  ; 
    fstream fin ; 
    fin.open(FileNme);

    while (fin)
    {
        getline(fin,line);
        Found= line.find("type");
        if (Found!=string::npos)
        {
            NubmberOfComponent++;
        }


    }

    return NubmberOfComponent ;

}


void ReadTopology (component *Copy_Object , string FileName,int NumberOfComponent)
{
    int NumberOfTerminal ;

    string IdTopology ;
    int Counter =0 ;
    string line ;
    int Found ;
    int CounterId =0;

    string Default ; 
    string Min ; 
    string Max ;

    int FirstIndex ;
    int LastIndex ;



   ifstream fin ; 
   fin.open(FileName);

    //Number of comonent has same id of topology 
    for (int i =0 ; i <NumberOfComponent ; i++)
    {
        NumberOfTerminal = GetNumberofTerminal(FileName,fin.tellg());
        string NameTerminal1[NumberOfTerminal]  ;
        string ConnectTerminal1[NumberOfTerminal] ;


    
        if (Counter == 0 )
        {
            Counter =1 ;
            while (fin)
            {
                getline(fin,line);
                Found = line.find("\"id\": ");
                if (Found!=string::npos)
                {
                    IdTopology= ExtractString (line,Found+6,line.length()-2);
                    break;
                }
            }

        }
        Copy_Object[i].Toplogy_voidSetId(IdTopology);

        while (fin)
        {
            getline(fin,line);
            Found = line.find("\"id\": ");
            if (Found!=string::npos)
            {
                Copy_Object[i].Type_voidComponentSetId(ExtractString (line,Found+6,line.length()-2));
                
                
            }
            Found = line.find("\"type\": ");
            if (Found!=string::npos)
            {
                Copy_Object[i].Type_voidComponentSetType(ExtractString (line,Found+8,line.length()-2));
                
            }
            Found = line.find("\"default\": ");
            if (Found!=string::npos)
            {
                Default = ExtractString (line,Found+11,line.length()-2) ; 
               
                
            }
            Found = line.find("\"min\": ");
            if (Found!=string::npos)
            {
                Min = ExtractString (line,Found+7,line.length()-2) ; 
                
            }
            Found = line.find("\"max\": ");
            if (Found!=string::npos)
            {
                
                Max = ExtractString (line,Found+7,line.length()-1) ;
                Copy_Object[i].Type_voidComponentSetTolarance(Default , Min ,Max);
                

            }

            Found = line.find("\"netlist\": ");
            if (Found != string::npos)
            {
                    int FirstIndex ;
                    int LastIndex ;
                for (int j =0 ; j<NumberOfTerminal;j++)
                {
                    getline(fin,line);
                    if (line != "")
                    {
                        FirstIndex = line.find ("\"");
                        if (FirstIndex != string::npos)
                        {
                            LastIndex = line.find(": ");
                            if (LastIndex != string::npos)
                            {

                                NameTerminal1[j] = ExtractString(line,FirstIndex,LastIndex-1);

                                if (line.find(",")!=string::npos)
                                {
                                    ConnectTerminal1[j] =ExtractString(line,LastIndex+2,line.length()-2);
                                }
                                else{
                                    ConnectTerminal1[j] =ExtractString(line,LastIndex+2,line.length()-1);

                                }                            }

                        }
                    }
                    else 
                    {
                        continue; 
                    }
                }


                if (NumberOfTerminal == 2 )
                {
                    Copy_Object[i].Type_voidComponentSetNameNetlist (NameTerminal1[0],NameTerminal1[1]);
                    Copy_Object[i].Type_voidComponentSetConnectNetlist(ConnectTerminal1[0],ConnectTerminal1[1]);
                    break ;

                }
                else if (NumberOfTerminal == 3)
                {
                    Copy_Object[i].Type_voidComponentSetNameNetlist (NameTerminal1[0],NameTerminal1[1],NameTerminal1[2]);
                    Copy_Object[i].Type_voidComponentSetConnectNetlist(ConnectTerminal1[0],ConnectTerminal1[1],ConnectTerminal1[2]);
                    break;
                }

            }



        }

        
    }
    fin.close();
}
void WriteToplogy (component *Copy_Object , string FileName , int NumberOfComponent)
{
    string Default ; 
    string Min ; 
    string Max ; 
    string TerminalName1 ;
    string TerminalName2 ;
    string TerminalName3 ;
    string TerminalConn1 ;
    string TerminalConn2 ;
    string TerminalConn3 ;

    ofstream fout ; 
    fout.open(FileName);
    fout<<"{"<<endl ;
    fout<<" \"id\": "<<Copy_Object[0].Toplogy_voidGetId()<<endl;
    fout<<" \"component\": ["<<endl;
    
    for (int i =0 ; i<NumberOfComponent;i++)
    {   
        TerminalName1="";
        TerminalName2="";
        TerminalName3="";
        TerminalConn1="";
        TerminalConn2="";
        TerminalConn3="";
        fout<<"  {"<<endl;
        fout<<"     \"type\": "<<Copy_Object[i].Type_voidComponentGetType()<<endl;
        fout<<"     \"id\": "<<Copy_Object[i].Type_voidComponentGetId()<<endl;
        fout<<"     "<<Copy_Object[i].Type_voidComponentGetId()<<": {"<<endl;
        Copy_Object[i].Type_voidComponentGetTolarance(&Default,&Min,&Max);
        fout<<"        \"default\": "<<Default<<","<<endl;
        fout<<"        \"min\": "<<Min<<","<<endl;
        fout<<"        \"max\": "<< Max<<endl;
        fout<<"      },"<<endl;
        fout<<"      \"netlist\": {"<<endl;
        Copy_Object[i].Type_voidComponentGetNetlist(&TerminalName1,&TerminalName2,&TerminalName3,&TerminalConn1,&TerminalConn2,&TerminalConn3);
        fout<<"        "<<TerminalName1<<": "<<TerminalConn1<<","<<endl;
        fout<<"        "<<TerminalName2<<": "<<TerminalConn2;
        if (TerminalName3 != "")
        {
            fout<<","<<endl;
            fout<<"        "<<TerminalName3<<": "<<TerminalConn3;
        }
        fout<<endl<<"      }"<<endl ;
        fout<<"  },"<<endl;
    }
    fout<<"}"<<endl;
}
void DeleteTopology (Topolgy *Copy_top)
{

    delete Copy_top ;
}
void QueryDevices (component *Copy_Object , int NumberOfComponent)
{
    string TerminalName1="";
    string TerminalName2="";
    string TerminalName3="";
    string TerminalConn1="";
    string TerminalConn2="";
    string TerminalConn3="";
    string Default ; 
    string Min ; 
    string Max ; 
    for (int i=0;i<NumberOfComponent;i++)
    {
        cout << "the"<<i+1<<"component"<<endl ;
        cout << "the Type of Component"<<Copy_Object[i].Type_voidComponentGetType();
        cout << "the Id of Component" << Copy_Object[i].Type_voidComponentGetId();
        Copy_Object[i].Type_voidComponentGetTolarance(&Default,&Min,&Max);
        cout << "Default: "<<Default<<endl ;
        cout << "Min: " <<Min<<endl ;
        cout << "Max" << Max <<endl ;
        Copy_Object[i].Type_voidComponentGetNetlist(&TerminalName1,&TerminalName2,&TerminalName3,&TerminalConn1,&TerminalConn2,&TerminalConn3);
        cout<<TerminalName1<<": "<<TerminalConn1<<endl;
        cout<<TerminalName2<<": "<<TerminalConn2<<endl;
        if (TerminalName3 != "")
        {
            
            cout<<TerminalName3<<": "<<TerminalConn3;
        }

    }

}
string QueryNetlist (component *Copy_Object,int NumberComponent , string TerminalName1_1,string TerminalName2_2,string TerminalName3_3,string TerminalConn1_1,string TerminalConn2_2,string TerminalConn3_3)
{
    string TerminalName1="";
    string TerminalName2="";
    string TerminalName3="";
    string TerminalConn1="";
    string TerminalConn2="";
    string TerminalConn3="";
    for (int i=0;i<NumberComponent;i++)
    {   
        Copy_Object[i].Type_voidComponentGetNetlist(&TerminalName1,&TerminalName2,&TerminalName3,&TerminalConn1,&TerminalConn2,&TerminalConn3);
    
        if (TerminalName3_3 != "")
        {
            if ((TerminalName1==TerminalName1_1)&&(TerminalName2==TerminalName2_2)&&(TerminalName3==TerminalName3_3)&&(TerminalConn1==TerminalConn1_1)&&(TerminalConn2==TerminalConn2_2)&&(TerminalConn3==TerminalConn3_3))
            {
                 return Copy_Object[i].Type_voidComponentGetType();

            }
        }
        else
        {
            
            if ((TerminalName1==TerminalName1_1)&&(TerminalName2==TerminalName2_2)&&(TerminalConn1==TerminalConn1_1)&&(TerminalConn2==TerminalConn2_2))
            {
                 return Copy_Object[i].Type_voidComponentGetType();

            }

        }
        
    }
    return "0" ;


}