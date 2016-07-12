// 
//  PCFG_Classifier.cpp
//
//
//  Created by aljohara on 6/10/16.
//
//

#include <stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cassert>
#include<iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;





//NT array elemnts
class melm {
public:
    string rule;
    long double e;
    melm();
};

melm::melm() {
    
    rule="";
    e=-999;
};


#include "IEprob.h"
#include "EIprob.h"





//92 is the number of Intron/Exon grammar rules
//Associate probabilities to each rule accordingly

long double IEERR[92]={
    1,1,1,1,
    1,1,1,1,
    1,1,1,1,
    1,1,1,1,
    1,1,1,1,
    1,1,1,1,
    1,1,
    0.51,0.15,0.19,0.15,
    0.44,0.21,0.25,0.10,
    0.50,0.10,0.31,0.10,
    0.53,0.10,0.21,0.15,
    0.60,0.10,0.24,0.06,
    0.49,0.06,0.30,0.15,
    0.49,0.07,0.33,0.11,
    0.45,0.09,0.28,0.19,
    0.45,0.07,0.36,0.12,
    0.57,0.04,0.36,0.03,
    0.58,0.05,0.28,0.10,
    0.29,0.24,0.22,0.25,
    0.31,0.01,0.65,0.04,
    1,
    1,
    0.08,0.52,0.18,0.22,
    0.37,0.25,0.25,0.17,
    0.28,0.20,0.32,0.19};


melm IEgram[92][92];  //array to store Intron/Exon grammar

//62 is the number of Intron/Exon grammar rules
//Associate probabilities to each rule accordingly

long double EIERR[62]={
    1,1,1,1,
    1,1,1,1,
    1,1,1,1,
    1,1,1,1,
    1,1,1,1,
    0.20,0.19,0.30,0.30,
    0.07,0.09,0.43,0.40,
    0.13,0.12,0.12,0.64,
    0.12,0.73,0.06,0.09,
    1,
    1,
    0.06, 0.29,0.02,0.62,
    0.12,0.12,0.09,0.68,
    0.05,0.84,0.02,0.09,
    0.63,0.09,0.12,0.17,
    0.22,0.18,0.21,0.39,
    0.26,0.20,0.29,0.24};


melm EIgram[62][62];  //array to store Intron/Exon grammar






    int  main()
        {
            
            cout<<"loading EXON/INTRON splice site grammar... \n";
            // EI and IE grammar in matrix
            string str,a, temp;
            
            ifstream myfile1("IEgrammar.txt");
            
            
            int counter=0;
            string word;
            while (counter<92)
            {
                
                
                getline(myfile1, a);
                istringstream linestream(a);
 
                
                
                //get lhs non-terminal
                linestream>>word;
                IEgram[counter][0].rule=word;
                
                //get arrow between grammar rules
                linestream>>word;
                
                
                //read first NT/T in rhs
                linestream>>word;
                
                
                if (word=="T"||word=="G"||word=="A"||word=="C")
                {
                    IEgram[counter][1].rule=word;
                    IEgram[counter][0].e=IEERR[counter];
                    
                    
                }
                //if there is still another NT in rhs read it
                else
                {
                    linestream>>temp;
                    temp= word+ ' ' + temp;
                    IEgram[counter][1].rule = temp;
                    IEgram[counter][0].e = IEERR[counter];
                    
                }
                
                counter++;
            }
            myfile1.close();
            
            cout<<"loading INTRON/EXON splice site grammar... \n";
            
            ifstream myfile2("EIgrammar.txt");
            
            
            counter=0;
            while (counter<62)
            {
                
                getline(myfile2, a);
                istringstream linestream(a);
                
                //get lhs non-terminal
                linestream>>word;
                EIgram[counter][0].rule=word;
                
                //get arrow between grammar rules
                linestream>>word;
                
                
                //read first NT/T in rhs
                linestream>>word;
                
                
                if (word=="T"||word=="G"||word=="A"||word=="C")
                {
                    EIgram[counter][1].rule=word;
                    EIgram[counter][0].e=EIERR[counter];
                    
                    
                }
                //if there is still another NT in rhs read it
                else
                {
                    linestream>>temp;
                    temp= word+ ' ' + temp;
                    EIgram[counter][1].rule = temp;
                    EIgram[counter][0].e = EIERR[counter];
                    
                }
                
                counter++;
            }
            myfile2.close();
            
            //////////////////////////////////////////////////
            
        cout<<"Start of classification.. \n";
            
        ifstream inputfile ("sample.txt");
            if (inputfile.is_open())
            {
            
       
        ofstream outputfile;
        outputfile.open ("RESULTS.txt");
            double p=-99;
            int z=0;
            int t1=0, t2=0;
            EI EIstring;
            IE IEstring;
            double EIp, IEp;
            string N;
            
        while(! inputfile.eof()){
           // cout<<z<<endl;
            //z++;
            inputfile >> N;
            inputfile >> N;
            
            //getline(inputfile, str);
            
            inputfile >> str;
            cout<<str << '\t';
            outputfile << str << '\t';
            EIp=EIstring.prob(str, EIgram);
            IEp=IEstring.prob(str, IEgram);
            
            
            //0.0000001 is the Intron/Exon splice site probability threshold
            //0.0005is the Intron/Exon splice site probability threshold
            
            //If accepted by both grammars find the one that is the closest to the
            //threshold
            
            if((IEp>0.0000001)&&(EIp>0.0005)){
                t1=IEp-0.0000001;
                t2=EIp-0.0005;
                if(t1>t2){
                    cout<<"IE";
                    outputfile<<"IE";
                }
                else{
                    cout<<"EI";
                    outputfile<<"EI";
                }
                
            }else{
                // If less than both thresholds it is calssified as not a splice-junction site
                if((IEp<=0.0000001)&&(EIp<=0.0005)){
                    cout<<"N";
                    outputfile<<"N";}
    
                if(IEp>0.0000001){
                    cout<< "IE";
                    outputfile<<"IE";}
                if(EIp>0.0005){
                    cout<<"EI";
                outputfile<<"EI";
                }
        

            }

            
        cout<<'\n';
        outputfile << '\n';
  
        
        
    }        outputfile.close();
            inputfile.close();
                               cout<<"DONE. Results saved in RESULTS.TXT file \n";
            }
            else
            {
                cout << "******** Error opening sample file ******** \n";
            }

         
     return 0;
}


