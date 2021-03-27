#include <iostream>
#include <sstream> // lai parveidotu string 
#include <vector> 
#include <fstream> //lasit no failiem un rakstit
#include <string>
#include <chrono> //biblioteka laikam

using namespace std;
using namespace chrono;

// bubblesort algortims sakuma salidzinia pirmos blakus esosos elementus, mazakais tiek novietots sakartotaja pozicija. Tad salidzina 2. ar 3 un ta talak.. un tad tiesi ta pat otra virziena 

void bubbleSort(vector<string> &vector)
{
	int i, j;
	string temp;
	
	for(i=0;i < vector.size();i++)
	{
		for(j=0;j < vector.size() - i - 1;j++)
		{	
	 	 // salidzina blakus esosos elementus
			if(vector[j] > vector[j + 1])
			{
				//samaina vietam
				temp = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = temp;						
			}	
		}
	}	
}	

int main() 
{ 
	bool firsTime=true;  //mainigais prieks tabulas kollonu nosaukumu izvades 
	int apjoms =0;  //mainigais prieks datu apjoma
 	int i = 0; 
 	double time1, time2, time3;  // mainigais prieks uznemtajiem laikiem vektora kartosanai
 	
 	microseconds duration;
 	
 	ifstream in("dati.csv"); // csv faila  ielade
 	ofstream out("izejosais.csv"); //izejosais csv fails izpildes rezultatam
 	
	vector <string> pirmais;  // vektors prieks pirma masiva datiem no csv faila
	vector <string> otrais; // vektors prieks otra masiva datiem no csv faila
	vector <string> tresais; // vektors prieks tresa masiva datiem no csv faila
	vector <double> izejosais; //vektors prieks izejosajiem datiem uz csv failu
	
	int j=10; // sakuma apjoms 10	
	
	while(j < 1000){ //no j apjoma lidz 1000
			
	// ielasa faila lidz j apjomam
	for (int i=1; i <= j; i++){ 
	string p, o, t, line;	
	getline(in, line);
		stringstream ss(line);
		getline(ss, p, ','); // ielasa lidz komatam
			pirmais.push_back(p); // vektora ielasa pirmo masivu kur augosa seciba dati
		getline(ss, o, ','); // ielasa lidz komatam
			otrais.push_back(o); // vektora ielasa otro masivu kur dilstosa seciba dati		
		getline(ss, t, ','); // ielasa lidz komatam
			tresais.push_back(t); // vektora ielasa treso masivu kur random seciba dati
		apjoms = i;
		
	}

	cout << "Datu apjoms: " << apjoms << endl; 
	izejosais.push_back(apjoms);

//------------------- laika uznemsana vektoru kartosanai------------------------------------	

	steady_clock::time_point t1 = steady_clock::now(); // sakuma laiks	
	/*vector<string> sortedArray1 =*/ bubbleSort(pirmais); // padod kartosanas funkcijai vektoru
	steady_clock::time_point t2 = steady_clock::now(); //beigu laiks
	
	duration = duration_cast<microseconds>(t2 - t1); // no beigu laika atnem sakuma laiku un iegust rezultatu
	time1 = duration.count(); // saglaba laiku mainigaja time1
	izejosais.push_back(time1); // ieliek vektora piefikseto laiku
	cout << "1. masiva skirosana " << time1 << " mikrosekundes" << endl;
		
	t1 = steady_clock::now();
    /*vector<string> sortedArray2 =*/ bubbleSort(otrais);
	t2 = steady_clock::now();
	
	duration = duration_cast<microseconds>(t2 - t1);
	time2 = duration.count();
	izejosais.push_back(time2);
	cout << "2. masiva skirosana " << time2<< " mikrosekundes" << endl;

	
	t1 = steady_clock::now();
	/*vector<string> sortedArray3 =*/ bubbleSort(tresais);
	t2 = steady_clock::now();
	
	duration = duration_cast<microseconds>(t2 - t1);
	time3 = duration.count();
	izejosais.push_back(time3);
	cout << "3. masiva skirosana " << time3 << " mikrosekundes" << endl;
	

	j=j*2; // palielina apjomu
	
/*		for (size_t i = 0; i < pirmais.size(); i++)
		cout << pirmais[i] << "\t" << otrais[i] << "\t" << tresais[i] << endl;*/

	pirmais.clear(); // attira vektoru
	otrais.clear(); // attira vektoru
	tresais.clear(); // attira vektoru

/*	for (size_t i = 0; i < sortedArray1.size(); i++)
		cout << sortedArray1[i] << "\t" << sortedArray2[i] << "\t" << sortedArray3[i] << endl;
		cout << "---------" << endl;

*/
	}
	in.close();
	// datu izvade faila
	for(int i = 0; i < izejosais.size(); i+=4){
		
		if (firsTime){
		//kolonnu nosaukumi
		out << "Datu apjoms" << "," << "Atraka masiva izpildes laiks" << "," << "Lenaka masiva izpildes laiks" << "," << "Videja masiva izpildes laiks" << "\n";
		firsTime = false;
		}
	
		out << izejosais[i] << "," << izejosais [i+1] << "," << izejosais[i+2] << "," << izejosais[i+3] << "\n";
	}
	out.close();

	return 0;
}

 


