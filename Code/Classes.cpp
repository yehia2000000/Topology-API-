#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std ; 


class Topolgy 
{
    private :
        string id ;
    public : 
        void Toplogy_voidSetId (string Copy_StringTopologyID);
        string Toplogy_voidGetId (void);

};

class component : public Topolgy
{
private :
    //type and id of the component 
    string type ;
    string ComponentId  ;
    // parameters of the tolarance 
    string default_comp ;
    string Min ; 
    string Max ; 

    // parameter of the netlist 
    string Termnial1_name ;
    string Terminal2_name ;
    string Terminal3_name ;

    string Terminal1_connection ; 
    string Terminal2_connection ;
    string Terminal3_connection ;

public : 
    void Type_voidComponentSetType (string Copy_StringTypeComponent );
    void Type_voidComponentSetId   (string Copy_StringIdComponent );

    string  Type_voidComponentGetType ();
    string  Type_voidComponentGetId   ();

    void Type_voidComponentSetTolarance (string Copy_StringDefaultComponent, string Copy_StringMinComponent , string Copy_StringMaxComponent );
    void Type_voidComponentSetNameNetlist   (string Copy_StringTermnial1_nameComponent , string Copy_StringTermnial2_nameComponent ,string Copy_StringTermnial3_nameComponent  );
    void Type_voidComponentSetNameNetlist   (string Copy_StringTermnial1_nameComponent , string Copy_StringTermnial2_nameComponent );

    void Type_voidComponentSetConnectNetlist   (string Copy_StringTermnial1_ConnectComponent , string Copy_StringTermnial2_ConnectComponent ,string Copy_StringTermnial3_ConnectComponent  );
    void Type_voidComponentSetConnectNetlist   (string Copy_StringTermnial1_ConnectComponent , string Copy_StringTermnial2_ConnectComponent );

    void Type_voidComponentGetTolarance (string *Copy_StringDefaultComponent ,string *Copy_StringMinComponent ,string *Copy_StringMaxComponent   );
    

    void Type_voidComponentGetNetlist (string *Copy_StringTermnial1_nameComponent , string* Copy_StringTermnial2_nameComponent ,string* Copy_StringTermnial3_nameComponent ,string *Copy_StringTermnial1_ConnectComponent, string *Copy_StringTermnial2_ConnectComponent, string *Copy_StringTermnial3_ConnectComponent );
    void Type_voidComponentGetNetlist (string* Copy_StringTermnial1_nameComponent , string *Copy_StringTermnial2_nameComponent ,string *Copy_StringTermnial1_ConnectComponent, string *Copy_StringTermnial2_ConnectComponent);



};

void  Topolgy ::Toplogy_voidSetId (string Copy_StringTopologyID)
{
    id = Copy_StringTopologyID ; 

}
string Topolgy ::Toplogy_voidGetId (void)
{

    return id ; 
}

void component ::Type_voidComponentSetType (string Copy_StringTypeComponent )
{
        type = Copy_StringTypeComponent ;
}
void component ::Type_voidComponentSetId   (string Copy_StringIdComponent )
{
    ComponentId = Copy_StringIdComponent ; 
}
string component :: Type_voidComponentGetType ()
{
    return type ;
}
string component :: Type_voidComponentGetId   ()
{
    return ComponentId ; 

}
void component ::Type_voidComponentSetTolarance (string Copy_StringDefaultComponent, string Copy_StringMinComponent , string Copy_StringMaxComponent )
{
     default_comp = Copy_StringDefaultComponent ;
     Min = Copy_StringMinComponent ; 
     Max = Copy_StringMaxComponent; 

}
void component ::Type_voidComponentSetNameNetlist (string Copy_StringTermnial1_nameComponent , string Copy_StringTermnial2_nameComponent ,string Copy_StringTermnial3_nameComponent  )
{
    Termnial1_name = Copy_StringTermnial1_nameComponent;
    Terminal2_name = Copy_StringTermnial2_nameComponent;
    Terminal3_name = Copy_StringTermnial3_nameComponent;


}
void component :: Type_voidComponentSetNameNetlist (string Copy_StringTermnial1_nameComponent , string Copy_StringTermnial2_nameComponent )
{
    Termnial1_name = Copy_StringTermnial1_nameComponent;
    Terminal2_name = Copy_StringTermnial2_nameComponent;

}

void component :: Type_voidComponentSetConnectNetlist   (string Copy_StringTermnial1_ConnectComponent , string Copy_StringTermnial2_ConnectComponent ,string Copy_StringTermnial3_ConnectComponent  )
{
    Terminal1_connection = Copy_StringTermnial1_ConnectComponent; 
    Terminal2_connection = Copy_StringTermnial2_ConnectComponent;
    Terminal3_connection = Copy_StringTermnial3_ConnectComponent ;

}
void component :: Type_voidComponentSetConnectNetlist   (string Copy_StringTermnial1_ConnectComponent , string Copy_StringTermnial2_ConnectComponent )
{
    Terminal1_connection = Copy_StringTermnial1_ConnectComponent ; 
    Terminal2_connection = Copy_StringTermnial2_ConnectComponent ;

}
void component ::Type_voidComponentGetTolarance (string *Copy_StringDefaultComponent ,string *Copy_StringMinComponent ,string *Copy_StringMaxComponent   )
{
    *Copy_StringDefaultComponent  = default_comp;
    *Copy_StringMaxComponent    = Max ;
    *Copy_StringMinComponent    = Min ;


}

void component ::Type_voidComponentGetNetlist (string *Copy_StringTermnial1_nameComponent , string* Copy_StringTermnial2_nameComponent ,string* Copy_StringTermnial3_nameComponent ,string *Copy_StringTermnial1_ConnectComponent, string *Copy_StringTermnial2_ConnectComponent, string *Copy_StringTermnial3_ConnectComponent )
{
    *Copy_StringTermnial1_nameComponent =  Termnial1_name;
    *Copy_StringTermnial2_nameComponent =  Terminal2_name;
    *Copy_StringTermnial3_nameComponent =  Terminal3_name;

    *Copy_StringTermnial1_ConnectComponent =Terminal1_connection;
    *Copy_StringTermnial2_ConnectComponent =Terminal2_connection;
    *Copy_StringTermnial3_ConnectComponent= Terminal3_connection;


}
void component ::Type_voidComponentGetNetlist (string* Copy_StringTermnial1_nameComponent , string *Copy_StringTermnial2_nameComponent ,string *Copy_StringTermnial1_ConnectComponent, string *Copy_StringTermnial2_ConnectComponent)
{
    *Copy_StringTermnial1_nameComponent =  Termnial1_name;
    *Copy_StringTermnial2_nameComponent =  Terminal2_name;
 

    *Copy_StringTermnial1_ConnectComponent =Terminal1_connection;
    *Copy_StringTermnial2_ConnectComponent =Terminal2_connection;


}
