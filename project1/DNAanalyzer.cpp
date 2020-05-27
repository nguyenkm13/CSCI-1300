// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 1 - Problems 4-7

#include <iostream>
using namespace std;

/*
* This function returns a similarity score of two DNA sequences.
* Parameters: seq1 - string of Sequence 1, seq2 - string of Sequence 2
* Return: similarity score
*/

double calcSimScore(string seq1, string seq2)
{
    double similarity_score;
    if(seq1 == seq2)
    {
        similarity_score = 1;
    }
    if((seq1.length() != seq2.length()) || seq1.length() == 0 || seq2.length() == 0)
    {
        similarity_score = 0;
    }
    
    else
    {
        int hamming = 0;
        for(int i = 0; i <= seq1.length(); i++)
        {
            if(seq1[i] != seq2[i])
            {
               hamming++; 
            }
        }
        similarity_score = (seq1.length() - hamming) / float(seq1.length());
    }
    
    return similarity_score;
}

/*
* This function takes a genome and a sequence and returns the highest similarity score found in the genome.
* Parameters: genome - string parameter for the genome, sequence - string parameter for the sequence
* Return: highest similarity score
*/

double findBestSimScore(string genome, string sequence)
{
    double sim_score = 0;
    
    for(int i = 0; i <= genome.length(); i++)
    {
        if(calcSimScore(sequence, genome.substr(i,sequence.length())) > sim_score)
        {
            sim_score = calcSimScore(sequence, genome.substr(i,sequence.length()));
        }
    }
    return sim_score;
}

/*
* This function takes three genomes and a sequence and prints the list of matched genomes.
* Parameters: gen1 - genome 1 as a string, gen2 - genome 2 as a string,
*   gen3 - genome 3 as a string, seq - sequence as a string
* Print: list of matched genomes
*/

void findMatchedGenome(string gen1, string gen2, string gen3, string seq)
{
    if (gen1 == "" || gen2 == "" || gen3 == "" || seq == "")
    {
        cout << "Genomes or sequence is empty." << endl;
    }
    else if (gen1.length() != gen2.length() && gen2.length() != gen3.length())
    {
        cout << "Lengths of genomes are different." << endl;
    }
    else 
    {
        double sim1, sim2, sim3;
        sim1 = findBestSimScore(gen1, seq); 
        sim2 = findBestSimScore(gen2, seq);
        sim3 = findBestSimScore(gen3, seq);
        if(sim1 >= sim2 && sim1 >= sim3)
        {
            cout << "Genome 1 is the best match." << endl;
        }
        if(sim2 >= sim1 && sim2 >= sim3)
        {
            cout << "Genome 2 is the best match." << endl;
        }
        if(sim3 >= sim1 && sim3 >= sim2)
        {
            cout << "Genome 3 is the best match." << endl;
        }
    }
}

int main()
{
    // string str1 = "AACT";
    // string str2 = "AATG";
    // cout << calcSimScore(str1, str2);
    
    // string g = "AATG";
    // string s = "AACT";
    // cout << findBestSimScore(g, s);
    
    // string gen1, gen2, gen3, seq_test;
    // gen1 = "AACT";
    // gen2 = "AACT";
    // gen3 = "AATG";
    // seq_test = "AACT";
    // findMatchedGenome(gen1, gen2, gen3, seq_test);
    
    // string g1 = "TAAGGCA";
    // string g2 = "TCTGGGC";
    // string g3 = "CTAATAT";
    // string seq = "AAG";
    // cout << g1 << endl << g2 << endl << g3 << endl << seq << endl;
    // findMatchedGenome(g1,g2,g3,seq);
    
    int selection = 0;
    while(selection != 4) 
    {
        cout << "Select a numerical option:\n" << "=== menu ===\n" << "1. Find similarity score\n" << "2. Find the best similarity score\n" 
            << "3. Analyze the genome sequences\n" << "4. Quit\n";
        cin >> selection;

        switch(selection)
        {
            case 1: 
            {
                string sequence1, sequence2;
                cout << "Enter sequence 1:\n";
                cin >> sequence1;
                cout << "Enter sequence 2:\n";
                cin >> sequence2;
                cout << "Similarity score: " << calcSimScore(sequence1, sequence2) << endl;
                break;
            }
            case 2: 
            {
                string genome, sequence;
                cout << "Enter genome:\n";
                cin >> genome;
                cout << "Enter sequence:\n";
                cin >> sequence;
                cout << "Best similarity score: " << findBestSimScore(genome, sequence) << endl;
                break;
            }
            case 3:
            {
                string genome1, genome2, genome3, sequence;
                cout << "Enter genome 1:\n";
                cin >> genome1;
                cout << "Enter genome 2:\n";
                cin >> genome2;
                cout << "Enter genome 3:\n";
                cin >> genome3;
                cout << "Enter sequence:\n";
                cin >> sequence;
                
                findMatchedGenome(genome1, genome2, genome3, sequence);
                break;
            }
            case 4:
            {
                cout << "Good bye!\n";
                break;
            }
            default:
            {
                cout << "Invalid option.\n";
            }
        } 
    }
    
    return 0;
}