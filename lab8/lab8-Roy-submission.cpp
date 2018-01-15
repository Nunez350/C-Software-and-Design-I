#include<iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

int splitSent(string sentence, string words[], int maxWords);//task 0
void replaceSmall(string words[],const unsigned int &maxWords, string ch1, string ch2);//task 1
int removeComp(string words[]);//Task 2
void removeDups(string words[], const unsigned int &maxWords);//task 3

//task 0. This is the prototype for a function that extracts and stores input from the command line then parses the data into iterative elements delimet by space characters, in other words storing each word from a sentence into an element into an array in sentence order. It also takes a constant unsigned permanant number argument defined in maxWords. If a string contains space characters and no letters it is not saved as an element. The total number of elements is returned in this function.

//Task 1. This function replaces small case "i" with upper case "I". This function loops through each iterative element in an array and compares it with ch1 which is "i". If this element matches ch1 then it is replaced with ch2 which is "I".

//Task 2. This function loops through each iterative element in an array, copies it into a temporary array of size 10,  and compares the copy with the literal string "science". If science is found it then compares the element preceding it to the word computer. If it matches the string computer then it replaces this element with CS and replaces the following with an empty strjng.  the literal sting science. it then returns the number of elements that fo not have empty strings. if this

//Task 3. This function loops thorough passed array and if one iteration is equal to the iteration preceding it, it replaces it with an empty string and then shifts in and compares subsequent iterations. It also prints out the element that was repeated.


int main() {
  const unsigned int maxWords = 10;//declared a constant insogned int variable because maxwords will be me unchancing parameter
  string sentence, words[maxWords];//declaring string variables sentence and the array words with size passed by maxwords
  string ch1= "i";//declaring string for the small case i 
  string ch2= "I"; //declaring string for upoer caee I
  cout<< "Please input a sentence that has ten words or less\n";//prompting input from the user at the comand line
  getline(cin,sentence);//making use of getting line predetetmined function to store all one lone inpit from the command line endterd by user
  if (splitSent(sentence, words,maxWords) < maxWords) {//intiating if statement to go continue on with the rest of the commands in int main if the size of the array or words os --, a condition initially mentioned and prompted for on the command line. if condition not met the program exits the loop and printe out error prompt 
    cout<< "\nThe original number of words in this sentence is:\n" <<splitSent(sentence, words,maxWords)<<endl;
            //    cout<<"no good"<<endl;
    removeDups(words,maxWords);//calling function will remove duplicates
    replaceSmall(words,maxWords,ch1,ch2);//calling function that will replace small case i with upper case I only if the array element if comprised of that letter
    cout<<"The revised number of words in this sentence is:\n"<<removeComp(words)<<endl; // printjng out the mumber of elements by calljng function
    cout<<"the new sentence is:\n";  //promtong out the new sentence
      for (int x =0;x<maxWords;x++) {//for statement that will loop through array and print out each iterarive elements
	cout<<words[x]<<" ";
      }cout<<endl<<endl;
  }else {
    cout<<"This sentence was not less than 20 words :/ "<<endl;//printing out error prompt if if statement was not met
  }
return 0;
}

//Task 0
int splitSent(string s, string words[], int maxWords) {
    int  j =0;
    string word = "";
    for (int i = 0; i<s.length(); i++) {
        if (s[i] == ' ') {//if an iteration equals a space character we assign that iteration an empty string and keep going through the sentence
            words[j]=word;
            word="";
            j++;
        } else {//if it doesnt contain a space character we assign this as a word
            word+=s[i];
        }
    }
    if (word != "") {//if each word is not an empty string we assign it to the array of words
        words[j]=word;
        j++;
    }
    return j;//function returns the number of words in array
}

//Task1
void replaceSmall(string words[], const unsigned int &maxWords, string ch1, string ch2) {
    for (int i = 0; i <maxWords; ++i) {
        if (words[i] == ch1) {//if the array iteration equals to ch1 which is small case "i", this loop assgns that element and replaces small case i with upper case "I"
            words[i] = ch2;
        }
    }
}
//Task 2
int removeComp(string words[]) {
    string temp[10];
    int count = 0;
    for (int i =0; i < 10; i++) {
        temp[count]=words[i];// as we loop through each iteration we assign it to element in an array
        //    if (count-1 >= 0)
        //cout << temp[count-1] << temp[count] << endl;
        if (count-1 >=0 && temp[count] == "science" && temp[count-1] == "computer") {//We go into this loop if the folowing conditions are met: we check if there is an element before this iteration to compare, we check if the element is "science" and we check if the iteration before it is "computer"
            //  cout<<"found computer science!"<<endl;
            temp[count-1]="CS";//if met, the preceding element is assigned "CS"
        } else if (temp[count] != "") { count++;}//if not met and iteration is not an empty string we count it as an array element
    }
    for (int j =0; j<10;j++) {//going through each element in an array that is as large as the temp array
        if (j <count) {
            words[j]=temp[j];//we copy each element back into the original array
        } else {words[j]="";   }//else we assign it an empty string
    }
    return count; //we return the number of elements in the array
}


//Task 2
void removeDups(string words[],const unsigned int &maxWords) {
  int i = 0;
  for (int j =1; j<maxWords; j++) {
    if (words[j] == words[j - 1] && words[j] !="") {//if the iterative elements equals the iteration before and it is not an empty string, we print out that element
      cout<<"The following word was repeated:\n" <<words[j];
      cout <<endl;
      for (int a=j;a<maxWords-1; a++) {//we shift elements in to continue comparing
	words[a]= words[a+1];
      }
      words[maxWords-1] = "";
      i++;
    }
  }
}










