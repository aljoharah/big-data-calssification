# big-data-calssification

A program to test classification using probabilistic context-free grammar.
For experimentation, splice-junction DNA sample was used. It classifies splice-junction sites into three categories:
-IE (Intron/Exon site or also referred to as "acceptors")
-EI (Exon/Intron site or also referred to as "donors")
-N (neither EI or IE)

Testing sample was collected from
https://archive.ics.uci.edu/ml/datasets/Molecular+Biology+(Splice-junction+Gene+Sequences)
Results are saved in reults.txt file.


*PCFG_Classifier.cpp:
Main program to classify data using probablitic context free grammar.

*EIprob.h and IEprob.h:
Header files containing Exon/Intron and Intron/Exon parsers respectively.

 *IEgrammar.txt:
 Contains the first category's grammar, Intron/Exon splice-junction site.
 
 *EIgrammar.txt:
  Contains the second grammar for the Exon/Intron splice-junction site.
