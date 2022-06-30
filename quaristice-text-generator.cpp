// lazy and uncommented code to generate quaristice style unicode text
// takes text from the command prompt and outputs it to output.txt

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

// very lazy, but very works
string mathify (char inChar)
{
	switch(inChar) {
		case 'A': return("𝘼");
		case 'B': return("𝘽");
		case 'C': return("𝘾");
		case 'D': return("𝘿");
		case 'E': return("𝙀");
		case 'F': return("𝙁");
		case 'G': return("𝙂");
		case 'H': return("𝙃");
		case 'I': return("𝙄");
		case 'J': return("𝙅");
		case 'K': return("𝙆");
		case 'L': return("𝙇");
		case 'M': return("𝙈");
		case 'N': return("𝙉");
		case 'O': return("𝙊");
		case 'P': return("𝙋");
		case 'Q': return("𝙌");
		case 'R': return("𝙍");
		case 'S': return("𝙎");
		case 'T': return("𝙏");
		case 'U': return("𝙐");
		case 'V': return("𝙑");
		case 'W': return("𝙒");
		case 'X': return("𝙓");
		case 'Y': return("𝙔");
		case 'Z': return("𝙕");
		case 'a': return("𝙖");
		case 'b': return("𝙗");
		case 'c': return("𝙘");
		case 'd': return("𝙙");
		case 'e': return("𝙚");
		case 'f': return("𝙛");
		case 'g': return("𝙜");
		case 'h': return("𝙝");
		case 'i': return("𝙞");
		case 'j': return("𝙟");
		case 'k': return("𝙠");
		case 'l': return("𝙡");
		case 'm': return("𝙢");
		case 'n': return("𝙣");
		case 'o': return("𝙤");
		case 'p': return("𝙥");
		case 'q': return("𝙦");
		case 'r': return("𝙧");
		case 's': return("𝙨");
		case 't': return("𝙩");
		case 'u': return("𝙪");
		case 'v': return("𝙫");
		case 'w': return("𝙬");
		case 'x': return("𝙭");
		case 'y': return("𝙮");
		case 'z': return("𝙯");
		case '1': return("𝟭");
		case '2': return("𝟮");
		case '3': return("𝟯");
		case '4': return("𝟰");
		case '5': return("𝟱");
		case '6': return("𝟲");
		case '7': return("𝟳");
		case '8': return("𝟴");
		case '9': return("𝟵");
		case '0': return("𝟬");
		default: return(string(1,inChar));
	}
}

int main()
{
	srand(time(0));
	
	string input = "";
	getline(cin,input);
	
	ofstream myfile;
	myfile.open ("output.txt");
	
	// this is a space + U+035F : COMBINING DOUBLE MACRON BELOW
	string underline = " ͟"; 
	
	myfile << underline << mathify(input[0]);
	input.erase(0,1);
	
	while (input.size() > 0)
	{
		int extra = 0;
		if (rand()%4 == 0)
			extra += 7;
		if (rand()%10 == 0)
			extra += 7;
				
		if (input[0] == ' ')
		{
			for (int i = 0; i < (rand()%10 + 3 + extra); i++)
			{
				myfile << " ";
			}
			input.erase(0,1);
			myfile << underline << mathify(input[0]);
		}
		else
		{
			for (int i = 0; i < (rand()%10 + 1 + extra); i++)
			{
				myfile << underline;
			}
			myfile << mathify(input[0]);
		}
		
		input.erase(0,1);
	}
	
	myfile.close();
	return 0;
}
