
class EI{


    public:


//melm gram[62][62];  //to store entered grammar




double prob(string str, melm gram[62][62])
{

    
    int i,k, n;
  //  string r;
    bool t;
    string A, B, C;
    long double L1, L2, L;
    
    long double S[59][59]= {{-999}},RS[59][59]= {{-999}}, EI0[59][59]= {{-999}}, EI1[59][59]= {{-999}}, EI2[59][59]= {{-999}}, EI3[59][59]= {{-999}}, EI4[59][59]= {{-999}}, EI5[59][59]= {{-999}}, EI6[59][59]= {{-999}}, EI7[59][59]= {{-999}}, EI8[59][59]= {{-999}}, EI9[59][59]= {{-999}}, EI10[59][59]= {{-999}}, X[59][59]= {{-999}}, X0[59][59]= {{-999}}, B4[59][59]= {{-999}},B3[59][59]= {{-999}},B2[59][59]= {{-999}},B1[59][59]= {{-999}},B01[59][59]= {{-999}}, B02[59][59]= {{-999}},B03[59][59]= {{-999}},B04[59][59]= {{-999}},B05[59][59]= {{-999}},B06[59][59]= {{-999}},B07[59][59]= {{-999}},B08[59][59]= {{-999}};
    

    
    ////////////////////////////FILL up "gram" matric with all rules//////////////////////////////////////////
    // gram[grammar number][0].rule is the rule left side
    // gram[grammar number][1].rule is the rule right side
    // gram[grammar number][0].e is the probability of that rules
    

        
      //  cout<<"\nEnter string to be checked : ";

        //cin >> str;
        int iLen= str.length();
        melm matrix[61][61][15];
        string st,h, temp;
        

        
        //fill the matrix with the terminal productions
        //Note to self: Working good dont miss with it
        for (int i=0; i<iLen; i++)
        {
            int x=0;
            for (int i1=0; i1<62; i1++)
            {
                /////look for the character [i] of the string if it exists in the right-hand side of the grammar
                if(gram[i1][1].rule.find(str[i])!=std::string::npos)
                {

                    

                //If it exists first put it in MATRIX PART
                    matrix[i][i][x].rule=gram[i1][0].rule;
                    matrix[i][i][x].e=gram[i1][0].e;
                               //     cout<<"i="<<i<<endl;
                    
                    //Then put it in the LIST PART
                    
                    //if(gram[i1][0].rule=="X")
                   // {
                    //    X[i][i]=gram[i1][0].e;
                  //  }
                    if(gram[i1][0].rule=="X0")
                    {
                        X0[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B4")
                    {
                       // if(gram[i1][1].rule=="t")
                            B4[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B3")
                    {
                        //if(gram[i1][1].rule=="t")
                            B3[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B2")
                    {
                       // if(gram[i1][1].rule=="g")
                            B2[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B1")
                    {
                      // if(gram[i1][1].rule=="a")
                           B1[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B01")
                    {
                       // if(gram[i1][1].rule=="c")
                            B01[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B02")
                    {
                        //if(gram[i1][1].rule=="a")
                            B02[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B03")
                    {
                       // if(gram[i1][1].rule=="t")
                            B03[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B04")
                    {
                       // if(gram[i1][1].rule=="a")
                            B04[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B05")
                    {
                       // if(gram[i1][1].rule=="t")
                            B05[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B06")
                    {
                        //if(gram[i1][1].rule=="a")
                            B06[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B07")
                    {
                        //if(gram[i1][1].rule=="a")
                            B07[i][i]=gram[i1][0].e;
                    }
                    if(gram[i1][0].rule=="B08")
                    {
                        //if(gram[i1][1].rule=="t")
                            B08[i][i]=gram[i1][0].e;
                    }
                    

                    

                    x++;
                   
                }
                
                
                
                
            }
         
            
        }
      
        
        
       // string R;
        int y=0;
        int x=0;
        int z=0;
        //fill the matrix with the nonterminal productions
     //   cout<<"fill the matrix with the nonterminal productions"<<endl;
        for (int s=1; s<iLen; s++)
             for(int i1=0; i1<62; i1++)
                for(int i=0; i+s<iLen; i++)
                    for(int k=i; k<s+i; k++)
                       
                    {
                        L1=-999;
                        //read the right side of the grammar rule
                        istringstream rhs(gram[i1][1].rule);
                        rhs >> B;
                        int y=0;
                        
                        //check if RHS non-terminal is in matrix or for a an empty space
                        while(B!=matrix[i][k][y].rule&& matrix[i][k][y].rule!="")
                        {y++;}
                        //if it already exists
                        if(B==matrix[i][k][y].rule)
                        {
                        if(rhs>>C){
                       
                            A=gram[i1][0].rule;
                            B.erase( remove_if(B.begin(), B.end(), ::isspace ), B.end() );
                            C.erase( remove_if(C.begin(), C.end(), ::isspace ), C.end() );
                            
                           // cout<<"//////////////////////////////////////"<<endl;
                            //cout<<"RULE "<<A<<" -> "<<B<< " "<<C<<endl;
                            
                            
                            //If first NT in the grammar rhs has a previous error value (error value not equal to -999) in LIST put the error value to L1
                            
                            if(B=="S")       if(S[i][k]!=-999)       L1=S[i][k];
                            if(B=="RS")      if(RS[i][k]!=-999)      L1=RS[i][k];
                            if(B=="EI0")     if(EI0[i][k]!=-999)     L1=EI0[i][k];
                            if(B=="EI1")     if(EI1[i][k]!=-999)     L1=EI1[i][k];
                            if(B=="EI2")     if(EI2[i][k]!=-999)     L1=EI2[i][k];
                            if(B== "EI3")    if(EI3[i][k]!=-999)     L1=EI3[i][k];
                            if(B== "EI4")    if(EI4[i][k]!=-999)     L1=EI4[i][k];
                            if(B== "EI5")    if(EI5[i][k]!=-999)     L1=EI5[i][k];
                            if(B== "EI6")    if(EI6[i][k]!=-999)     L1=EI6[i][k];
                            if(B== "EI7")    if(EI7[i][k]!=-999)     L1=EI7[i][k];
                            if(B== "EI8")    if(EI8[i][k]!=-999)     L1=EI8[i][k];
                            if(B== "EI9")    if(EI9[i][k]!=-999)     L1=EI9[i][k];
                            if(B== "EI10")   if(EI10[i][k]!=-999)    L1=EI10[i][k];
                            if(B== "X")      if(X[i][k]!=-999)       L1=X[i][k];
                            if(B== "X0")     if(X0[i][k]!=-999)      L1=X0[i][k];
                            if(B== "B4")     if(B4[i][k]!=-999)      L1=B4[i][k];
                            if(B== "B3")     if(B3[i][k]!=-999)      L1=B3[i][k];
                            if(B== "B2")     if(B2[i][k]!=-999)      L1=B2[i][k];
                            if(B== "B1")     if(B1[i][k]!=-999)      L1=B1[i][k];
                            if(B== "B01")    if(B01[i][k]!=-999)     L1=B01[i][k];
                            if(B== "B02")    if(B02[i][k]!=-999)     L1=B02[i][k];
                            if(B== "B03")    if(B03[i][k]!=-999)     L1=B03[i][k];
                            if(B== "B04")    if(B04[i][k]!=-999)     L1=B04[i][k];
                            if(B== "B05")    if(B05[i][k]!=-999)     L1=B05[i][k];
                            if(B== "B06")    if(B06[i][k]!=-999)     L1=B06[i][k];
                            if(B== "B07")    if(B07[i][k]!=-999)     L1=B07[i][k];
                            if(B== "B08")    if(B08[i][k]!=-999)     L1=B08[i][k];
                            
                             //  cout<<"B= "<<B <<" L1= "<<L1<<" B4[i][k]= "<<B4[i][k]<<endl;
                            
                            x=0;
                            bool found=false;
                            
                            //Look for part C of the rule if it exists in matrix
                           //    cout<<"matrix["<<k+1 << "]["<<i+s<<"]["<<0<<"].rule= "<<matrix[k+1][i+s][x].rule<<endl;
                            
                            while(matrix[k+1][i+s][x].rule!="" && matrix[k+1][i+s][x].rule!=C){
                                x++;}

                            
                                //if C found put the error value in L2
                                if(matrix[k+1][i+s][x].rule==C)
                                {
                                    
                                    
                                    L2=matrix[k+1][i+s][x].e;
                                    
                                    found=true;
                                
                                  //  cout<<"L1="<<L1<<" L2= "<<L2<<endl;
  
                                L=L1*L2*gram[i1][0].e;
                                    
                                
                                    A.erase( remove_if(A.begin(), A.end(), ::isspace ), A.end() );
                                int z=0;
                                    matrix[i][i+s][z].rule.erase(remove_if(matrix[i][i+s][z].rule.begin(), matrix[i][i+s][z].rule.end(), ::isspace ), matrix[i][i+s][z].rule.end() );
                                    while(matrix[i][i+s][z].rule!="" && matrix[i][i+s][z].rule!=A){
                                        matrix[i][i+s][z].rule.erase(remove_if(matrix[i][i+s][z].rule.begin(), matrix[i][i+s][z].rule.end(), ::isspace ), matrix[i][i+s][z].rule.end() );
            
                                        
                                    //    cout<<"B= "<<C<<" and matrix["<<i<<"]["<<k<<"]["<<z<<"].rule= "<<matrix[i][k][z].rule<<" error "<<matrix[i][k][z].e<<endl;
                                        
                                        
                                      z++;
                                    }
  
                                    
                                    
                                matrix[i][i+s][z].rule=A;
                                //      cout<<"matrix[i][i+s][z].rule after"<<matrix[i][i+s][z].rule<<endl;
                                  //      cout<<"After putting A in matrix["<<i<<"]["<<i+s<<"]"<< matrix[i][i+s][z].rule<<endl;;

                                    
                          
                                    //check if it is a new rule (error value =-999) set the value to current error sum
                                if(matrix[i][i+s][z].e==-999)
                                    matrix[i][i+s][z].e=L;
                                    
                                    //if it is not a new rule AND the error found is larger than the sum, set the sum to be the new error
                                if(matrix[i][i+s][z].e<L)
                                    matrix[i][i+s][z].e=L;
                                    
                                    
                                    
                                        if(A=="S")
                                            if(S[i][i+s]<L)
                                                S[i][i+s]=L;
                                        if(A=="RS")
                                            if(RS[i][i+s]<L)
                                                RS[i][i+s]=L;
                                        if(A=="EI0")
                                            if(EI0[i][i+s]<L)
                                                EI0[i][i+s]=L;
                                        if(A=="EI1")
                                            if(EI1[i][i+s]<L)
                                                EI1[i][i+s]=L;
                                        if(A== "EI2")
                                            if(EI2[i][i+s]<L)
                                                EI2[i][i+s]=L;
                                        if(A== "EI3")
                                            if (EI3[i][i+s]<L)
                                                EI3[i][i+s]=L;
                                        if(A== "EI4")
                                            if(EI4[i][i+s]<L)
                                                EI4[i][i+s]=L;
                                        if(A== "EI5")
                                            if(EI5[i][i+s]<L)
                                                EI5[i][i+s]=L;
                                        if(A== "EI6")
                                            if(EI6[i][i+s]<L)
                                                EI6[i][i+s]=L;
                                        if(A== "EI7")
                                            if(EI7[i][i+s]<L)
                                                EI7[i][i+s]=L;
                                        if(A== "EI8")
                                            if(EI8[i][i+s]<L)
                                                EI8[i][i+s]=L;
                                        if(A== "EI9")
                                            if(EI9[i][i+s]<L)
                                                EI9[i][i+s]=L;
                                        if(A== "EI10")
                                            if(EI10[i][i+s]<L)
                                                EI10[i][i+s]=L;
                                        if(A== "X")
                                            if(X[i][i+s]<L)
                                                X[i][i+s]=L;
                                        if(A== "X0")
                                            if(X0[i][i+s]<L)
                                                X0[i][i+s]=L;
                                        if(A== "B4")
                                            if(B4[i][i+s]<L)
                                                B4[i][i+s]=L;
                                        if(A== "B3")
                                            if(B3[i][i+s]<L)
                                                B3[i][i+s]=L;
                                        if(A== "B2")
                                            if(B2[i][i+s]<L)
                                                B2[i][i+s]=L;
                                        if(A== "B1")
                                            if(B1[i][i+s]<L)
                                                B1[i][i+s]=L;
                                        if(A== "B01")
                                            if(B01[i][i+s]<L)
                                                B01[i][i+s]=L;
                                        if(A== "B02")
                                            if(B02[i][i+s]<L)
                                                B02[i][i+s]=L;
                                        if(A== "B03")
                                            if(B03[i][i+s]<L)
                                                B03[i][i+s]=L;
                                        if(A== "B04")
                                            if(B04[i][i+s]<L)
                                                B04[i][i+s]=L;
                                        if(A== "B05")
                                            if(B05[i][i+s]<L)
                                                B05[i][i+s]=L;
                                        if(A== "B06")
                                            if(B06[i][i+s]<L)
                                                B06[i][i+s]=L;
                                        if(A== "B07")
                                            if(B07[i][i+s]<L)
                                                B07[i][i+s]=L;
                                        if(A== "B08")
                                            if(B08[i][i+s]<L)
                                                B08[i][i+s]=L;
                                    
                                }
                            
                            

                    }
                        }
                    }
        
        x=0;



    return S[0][iLen-1]*100 ;
        }

    /*
public:
    double  prob(string str, lelm gram[62][62])
        {
           
        double p=-99;
       
            p=getprob(str);

        
    }

     return p;
}*/
};

