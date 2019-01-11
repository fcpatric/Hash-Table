/// Lab 4, Hash Table
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751
/// DriverLab4.cpp

#include <iostream>
using std::ostream;
using std::cout;
using std::cin;

#include <string>
using std::string;

#include "Array.h"
#include "CollisionList.h"
#include "CDLHashTable.h"
#include "CircularDoublyLinkedList.h"

#include "MyStruct.h"

const int SIZE1 = 13, SIZE2 = 199;

int hash1(const MyStruct &obj);
int hash2(const MyStruct &obj);

int main()
{
	// programmer's identification
	cout << "Lab 4, Hash Table\n";
	cout << "Programmer: Fernando Ian Patricio\n";
	cout << "Programmer's ID: 1428751\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

	MyStruct myobj;
	myobj.str = "Whitesmith Harword";
	myobj.num = 1;

	MyStruct myobj2;
	myobj2.str = "High Wizard Katrinne";
	myobj2.num = 2;

	MyStruct myobj3;
	myobj3.str = "High Priest Magaletha";
	myobj3.num = 3;

	MyStruct myobj4;
	myobj4.str = "Lord Knight Seyren";
	myobj4.num = 4;

	MyStruct myobj5;
	myobj5.str = "Assassin Cross Eremes";
	myobj5.num = 5;

	MyStruct myobj6;
	myobj6.str = "Wounded Morroc";
	myobj6.num = 6;

	MyStruct myobj7;
	myobj7.str = "Eddga";
	myobj7.num = 7;

	MyStruct myobj8;
	myobj8.str = "Phreeoni";
	myobj8.num = 8;

	MyStruct myobj9;
	myobj9.str = "Valkyrie Randgris";
	myobj9.num = 9;

	MyStruct myobj10;
	myobj10.str = "lady Tanee";
	myobj10.num = 10;

	MyStruct myobj11;
	myobj11.str = "Amon Ra";
	myobj11.num = 11;

	MyStruct myobj12;
	myobj12.str = "Atroce";
	myobj12.num = 12;

	MyStruct myobj13;
	myobj13.str = "Bacsojin";
	myobj13.num = 13;

	MyStruct myobj14;
	myobj14.str = "Baphomet";
	myobj14.num = 14;

	MyStruct myobj15;
	myobj15.str = "Beelzebub";
	myobj15.num = 15;

	MyStruct myobj16;
	myobj16.str = "Ygnizem";
	myobj16.num = 16;

	MyStruct myobj17;
	myobj17.str = "Boitata";
	myobj17.num = 17;

	MyStruct myobj18;
	myobj18.str = "Champion Cena";
	myobj18.num = 18;

	MyStruct myobj19;
	myobj19.str = "Buwaya";
	myobj19.num = 19;

	MyStruct myobj20;
	myobj20.str = "Clown Alphoccio";
	myobj20.num = 20;

	MyStruct myobj21;
	myobj21.str = "Creator Flamel";
	myobj21.num = 21;

	MyStruct myobj22;
	myobj22.str = "General Daehyun";
	myobj22.num = 22;

	MyStruct myobj23;
	myobj23.str = "Dark Lord";
	myobj23.num = 23;

	MyStruct myobj24;
	myobj24.str = "Detale";
	myobj24.num = 24;

	MyStruct myobj25;
	myobj25.str = "Doppelganger";
	myobj25.num = 25;

	MyStruct myobj26;
	myobj26.str = "Dracula";
	myobj26.num = 26;

	MyStruct myobj27;
	myobj27.str = "Drake";
	myobj27.num = 27;

	MyStruct myobj28;
	myobj28.str = "Evil Snake Lord";
	myobj28.num = 28;

	MyStruct myobj29;
	myobj29.str = "Fallen Bishop Hibram";
	myobj29.num = 29;

	MyStruct myobj30;
	myobj30.str = "Garm";
	myobj30.num = 30;

	MyStruct myobj31;
	myobj31.str = "Gioia";
	myobj31.num = 31;

	MyStruct myobj32;
	myobj32.str = "Gloom Under Night";
	myobj32.num = 32;

	MyStruct myobj33;
	myobj33.str = "Gold Queen Scaraba";
	myobj33.num = 33;

	MyStruct myobj34;
	myobj34.str = "Golden Thief Bug";
	myobj34.num = 34;

	MyStruct myobj35;
	myobj35.str = "Gopinich";
	myobj35.num = 35;

	MyStruct myobj36;
	myobj36.str = "Gypsy Trentini";
	myobj36.num = 36;

	MyStruct myobj37;
	myobj37.str = "Ifrit";
	myobj37.num = 37;

	MyStruct myobj38;
	myobj38.str = "Incantation Samurai";
	myobj38.num = 38;

	MyStruct myobj39;
	myobj39.str = "Dark Guardian Kades";
	myobj39.num = 39;

	MyStruct myobj40;
	myobj40.str = "Kiel D-01";
	myobj40.num = 40;

	MyStruct myobj41;
	myobj41.str = "Stormy Knight";
	myobj41.num = 41;

	MyStruct myobj42;
	myobj42.str = "Kraken";
	myobj42.num = 42;

	MyStruct myobj43;
	myobj43.str = "Ktullanux";
	myobj43.num = 43;

	MyStruct myobj44;
	myobj44.str = "Kublin";
	myobj44.num = 44;

	MyStruct myobj45;
	myobj45.str = "Leak";
	myobj45.num = 45;

	MyStruct myobj46;
	myobj46.str = "Lord of the Dead";
	myobj46.num = 46;

	MyStruct myobj47;
	myobj47.str = "Lost Dragon";
	myobj47.num = 47;

	MyStruct myobj48;
	myobj48.str = "Maya";
	myobj48.num = 48;

	MyStruct myobj49;
	myobj49.str = "Mistress";
	myobj49.num = 49;

	MyStruct myobj50;
	myobj50.str = "Moonlight Flower";
	myobj50.num = 50;

	MyStruct myobj51;
	myobj51.str = "Nidhoggr's Shadow";
	myobj51.num = 51;

	MyStruct myobj52;
	myobj52.str = "Nightmare Amon Ra";
	myobj52.num = 52;

	MyStruct myobj53;
	myobj53.str = "Orc Hero";
	myobj53.num = 53;

	MyStruct myobj54;
	myobj54.str = "Orc Lord";
	myobj54.num = 54;

	MyStruct myobj55;
	myobj55.str = "Osiris";
	myobj55.num = 55;

	MyStruct myobj56;
	myobj56.str = "Paladin Randel";
	myobj56.num = 56;

	MyStruct myobj57;
	myobj57.str = "Pharaoh";
	myobj57.num = 57;

	MyStruct myobj58;
	myobj58.str = "Pori Pori";
	myobj58.num = 58;

	MyStruct myobj59;
	myobj59.str = "Professor Celia";
	myobj59.num = 59;

	MyStruct myobj60;
	myobj60.str = "Angry Student Pyuriel";
	myobj60.num = 60;

	MyStruct myobj61;
	myobj61.str = "Queen Scaraba";
	myobj61.num = 61;

	MyStruct myobj62;
	myobj62.str = "Root of Corruption";
	myobj62.num = 62;

	MyStruct myobj63;
	myobj63.str = "RSX 0806";
	myobj63.num = 63;

	MyStruct myobj64;
	myobj64.str = "RWC Boss";
	myobj64.num = 64;

	MyStruct myobj65;
	myobj65.str = "Sniper Cecil";
	myobj65.num = 65;

	MyStruct myobj66;
	myobj66.str = "Stalker Gertie";
	myobj66.num = 66;

	MyStruct myobj67;
	myobj67.str = "Tao Gunka";
	myobj67.num = 67;

	MyStruct myobj68;
	myobj68.str = "Thanatos";
	myobj68.num = 68;

	MyStruct myobj69;
	myobj69.str = "Turtle General";
	myobj69.num = 69;

	MyStruct myobj70;
	myobj70.str = "Vesper";
	myobj70.num = 70;

	CircularDoublyLinkedList<MyStruct> ht1(hash1, SIZE1);
	CircularDoublyLinkedList<MyStruct> ht2(hash2, SIZE2);

	cout << "Showing Empty List...\n";
	cout << "Hash Table 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST 1:\n";
	ht1.display();
	cout << endl;

	cout << "Inserting " << myobj.str << "(" << myobj.num << ")...\n";
	ht1.insert(myobj);
	cout << "Hash Table 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST 1:\n";
	ht1.display();
	cout << endl;

	cout << "Inserting " << myobj2.str << "(" << myobj2.num << ")...\n";
	ht1.insert(myobj2);
	cout << "Hash Table 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST 1:\n";
	ht1.display();
	cout << endl;

	cout << "Inserting " << myobj3.str << "(" << myobj3.num << ")...\n";
	ht1.insert(myobj3);
	cout << "Hash Table 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST 1:\n";
	ht1.display();
	cout << endl;

	cout << "Inserting " << myobj4.str << "(" << myobj4.num << ")...\n";
	ht1.insert(myobj4);
	cout << "Hash Table 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST 1:\n";
	ht1.display();
	cout << endl;

	cout << "Try to Find " << myobj3.str << "(" << myobj3.num << ")...\n";
	if (ht1.find(myobj3))
		cout << "Found!\n";
	else
		cout << "Not found\n";
	cout << endl;

	MyStruct myobj1000;
	myobj1000.str = "Nothing";
	myobj1000.num = 1000;
	cout << "Try to Find " << myobj1000.str << "(" << myobj1000.num << ")...\n";
	if (ht1.find(myobj5))
		cout << "Found!\n";
	else
		cout << "Not found!\n";
	cout << endl;

	cout << "Try to retrieve " << myobj2.str << "(" << myobj2.num << ")...\n";
	ht1.retrieve(myobj2);
	cout << myobj2;
	cout << endl << endl;

	cout << "Try to remove between of the list " << myobj3.str << "(" << myobj3.num << ")...\n";
	ht1.remove(myobj3);
	cout << "HASH TABLE 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST List 1:\n";
	ht1.display();
	cout << endl;

	cout << "Try to remove header of the list " << myobj4.str << "(" << myobj4.num << ")...\n";
	ht1.remove(myobj4);
	cout << myobj;
	cout << "HASH TABLE 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST List 1:\n";
	ht1.display();
	cout << endl;

	cout << "Try to remove trailer of the list " << myobj.str << "(" << myobj.num << ")...\n";
	ht1.remove(myobj);
	cout << "HASH TABLE 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST List 1:\n";
	ht1.display();
	cout << endl;

	cout << "Try to remove the only object in the list " << myobj2.str << "(" << myobj2.num << ")...\n";
	ht1.remove(myobj2);
	cout << "HASH TABLE 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST List 1:\n";
	ht1.display();
	cout << endl;

	cout << "Try to remove empty list " << myobj5.str << "(" << myobj5.num << ")...\n";
	ht1.remove(myobj5);
	cout << "HASH TABLE 1:\n";
	cout << ht1;
	cout << "CIRCULAR DOUBLY LINKED LIST 1:\n";
	ht1.display();
	cout << endl;

  /*
  {
	// test my struct operator <<
	cout << "test my struct operator<<...\n";
	cout << myobj;
	cout << endl;
	cout << endl;

	// test#1 collision list operator<<
	CollisionList<MyStruct> cl1;
	cout << "test#1 collision list operator<<...\n";
	cl1.insert(myobj);
	cl1.insert(myobj2);
	cl1.insert(myobj3);
	cl1.insert(myobj4);
	cout << cl1;
	cout << endl;
	cout << endl;

	// test#2 collision list operator<<
	CollisionList<MyStruct> cl2;
	cout << "test#2 collision list operator<<...\n";
	cl2.insert(myobj3);
	cl2.insert(myobj4);
	cl2.insert(myobj2);
	cl2.insert(myobj);
	cout << cl2;
	cout << endl;
	cout << endl;

	// test#1 array table operator <<
	cout << "test#1 array table operator<<...\n";
	Array<MyStruct> a1(4);
	a1[0] = myobj;
	a1[1] = myobj2;
	a1[2] = myobj3;
	a1[3] = myobj4;
	cout << a1;
	cout << endl;

	// test#2 array table operator <<
	cout << "test#2 array table operator<<...\n";
	Array< CollisionList<MyStruct> > a3(2);
	a3[0] = cl1;
	a3[1] = cl2;
	cout << a3;
	cout << endl;

	// test dl hash table operator<<
	cout << "test dl hash table operator<<...\n";
	DLHashTable<MyStruct> dlht1(hash1, SIZE1);
	dlht1.insert(myobj);
	dlht1.insert(myobj2);
	dlht1.insert(myobj3);
	dlht1.insert(myobj4);
	dlht1.insert(myobj5);
	dlht1.insert(myobj6);
	dlht1.insert(myobj7);
	dlht1.insert(myobj8);
	dlht1.insert(myobj9);
	dlht1.insert(myobj10);
	dlht1.insert(myobj11);
	dlht1.insert(myobj12);
	dlht1.insert(myobj13);
	dlht1.insert(myobj14);
	dlht1.insert(myobj15);
	dlht1.insert(myobj16);
	dlht1.insert(myobj17);
	dlht1.insert(myobj18);
	dlht1.insert(myobj19);
	dlht1.insert(myobj20);
	dlht1.insert(myobj21);
	dlht1.insert(myobj22);
	dlht1.insert(myobj23);
	dlht1.insert(myobj24);
	dlht1.insert(myobj25);
	dlht1.insert(myobj26);
	dlht1.insert(myobj27);
	dlht1.insert(myobj28);
	dlht1.insert(myobj29);
	dlht1.insert(myobj30);
	dlht1.insert(myobj31);
	dlht1.insert(myobj32);
	dlht1.insert(myobj33);
	dlht1.insert(myobj34);
	dlht1.insert(myobj35);
	dlht1.insert(myobj36);
	dlht1.insert(myobj37);
	dlht1.insert(myobj38);
	dlht1.insert(myobj39);
	dlht1.insert(myobj40);
	dlht1.insert(myobj41);
	dlht1.insert(myobj42);
	dlht1.insert(myobj43);
	dlht1.insert(myobj44);
	dlht1.insert(myobj45);
	dlht1.insert(myobj46);
	dlht1.insert(myobj47);
	dlht1.insert(myobj48);
	dlht1.insert(myobj49);
	dlht1.insert(myobj50);
	dlht1.insert(myobj51);
	dlht1.insert(myobj52);
	dlht1.insert(myobj53);
	dlht1.insert(myobj54);
	dlht1.insert(myobj55);
	dlht1.insert(myobj56);
	dlht1.insert(myobj57);
	dlht1.insert(myobj58);
	dlht1.insert(myobj59);
	dlht1.insert(myobj60);
	dlht1.insert(myobj61);
	dlht1.insert(myobj62);
	dlht1.insert(myobj63);
	dlht1.insert(myobj64);
	dlht1.insert(myobj65);
	dlht1.insert(myobj66);
	dlht1.insert(myobj67);
	dlht1.insert(myobj68);
	dlht1.insert(myobj69);
	dlht1.insert(myobj70);
	cout << dlht1;
  }
	*/

	CircularDoublyLinkedList<MyStruct> ht4(hash1, SIZE1);
	ht4.insert(myobj);
	ht4.insert(myobj2);
	ht4.insert(myobj3);
	ht4.insert(myobj4);
	ht4.insert(myobj5);
	ht4.insert(myobj6);
	ht4.insert(myobj7);
	ht4.insert(myobj8);
	ht4.insert(myobj9);
	ht4.insert(myobj10);
	ht4.insert(myobj11);
	ht4.insert(myobj12);
	ht4.insert(myobj13);
	ht4.insert(myobj14);
	ht4.insert(myobj15);
	ht4.insert(myobj16);
	ht4.insert(myobj17);
	ht4.insert(myobj18);
	ht4.insert(myobj19);
	ht4.insert(myobj20);
	ht4.insert(myobj21);
	ht4.insert(myobj22);
	ht4.insert(myobj23);
	ht4.insert(myobj24);
	ht4.insert(myobj25);
	ht4.insert(myobj26);
	ht4.insert(myobj27);
	ht4.insert(myobj28);
	ht4.insert(myobj29);
	ht4.insert(myobj30);
	ht4.insert(myobj31);
	ht4.insert(myobj32);
	ht4.insert(myobj33);
	ht4.insert(myobj34);
	ht4.insert(myobj35);
	ht4.insert(myobj36);
	ht4.insert(myobj37);
	ht4.insert(myobj38);
	ht4.insert(myobj39);
	ht4.insert(myobj40);
	ht4.insert(myobj41);
	ht4.insert(myobj42);
	ht4.insert(myobj43);
	ht4.insert(myobj44);
	ht4.insert(myobj45);
	ht4.insert(myobj46);
	ht4.insert(myobj47);
	ht4.insert(myobj48);
	ht4.insert(myobj49);
	ht4.insert(myobj50);
	ht4.insert(myobj51);
	ht4.insert(myobj52);
	ht4.insert(myobj53);
	ht4.insert(myobj54);
	ht4.insert(myobj55);
	ht4.insert(myobj56);
	ht4.insert(myobj57);
	ht4.insert(myobj58);
	ht4.insert(myobj59);
	ht4.insert(myobj60);
	ht4.insert(myobj61);
	ht4.insert(myobj62);
	ht4.insert(myobj63);
	ht4.insert(myobj64);
	ht4.insert(myobj65);
	ht4.insert(myobj66);
	ht4.insert(myobj67);
	ht4.insert(myobj68);
	ht4.insert(myobj69);
	ht4.insert(myobj70);
	// test doubly linked list operator<<
	cout << "HASH TABLE 4:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << ht4;
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << endl;

	cout << "CIRCULAR DOUBLY LINKED LIST 4:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	ht4.display();
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << endl;

  // test copy constructor
	CircularDoublyLinkedList<MyStruct> ht5(ht4);
	cout << "HASH TABLE 5:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << ht5;
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";

  cout << "CIRCULAR DOUBLY LINKED LIST 5:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	ht5.display();
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << endl;

	// test assignment operator
	CircularDoublyLinkedList<MyStruct> ht6 = ht4;
  cout << "HASH TABLE 6:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << ht6;
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";

  cout << "CIRCULAR DOUBLY LINKED LIST 6:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	ht6.display();
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << endl;

	// test make empty
	ht4.makeEmpty();
	cout << "HASH TABLE 4:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << ht4;
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << endl;

	cout << "CIRCULAR DOUBLY LINKED LIST 4:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	ht4.display();
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << endl;

	// test destructor
	ht5.~CircularDoublyLinkedList();
	cout << "HASH TABLE 5:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << ht5;
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";

	cout << "CIRCULAR DOUBLY LINKED LIST 5:\n";
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	ht5.display();
	cout << "-------------------------------------------------------------------------------------------------------";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << endl;

	// try to retrieve which is not in the list
	MyStruct obj7;
	ht6.retrieve(obj7);
	cout << obj7 << endl;

  cout << "Press Enter to End.";
	cin.get();
}

int hash1(const MyStruct &obj)
{
	int sum = 0;

	// before
	// for (int i = 0; i < 3 && i < int(obj.str.length()); i++)
	//for (int i = 0; i < int(obj.str.length()); i++)
		//sum += obj.str[i];

	//before
	//return sum % SIZE1;
	return int(obj.str.length()) % SIZE1;
}

int hash2(const MyStruct &obj)
{
	int sum = 0;
	for (int i = int( obj.str.length() ) - 1; i > -1 && i > int(obj.str.length()) - 7; i--)
		sum += obj.str[i];
	return sum % SIZE2;
}
