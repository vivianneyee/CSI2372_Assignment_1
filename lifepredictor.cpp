/**
* Vivianne Yee
* 300118867
**/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int simulate(int age, string sex) {
  // string that will hold each individual line
  string line;
  // read from the text file
  ifstream f("LifeDeathProbability.txt");
  // read from file line by line
  bool alive = true;
  double mprob;
  double fprob;

  for (int i = 0; i <= age; i++) {
    getline(f, line);
  }
  srand(time(0));
  // loop till person dies in simulation
  while(alive) {
    // get the age
    int pos = line.find(" ");
    line.erase(0, pos + 2);

    // get the male probability
    pos = line.find(" ");
    mprob = std::stod(line.substr(0, pos));

    // get the female probability
    line.erase(0, pos + 2);
    pos = line.find(" ");
    fprob = std::stod(line.substr(0, pos));

    // randomize a number between 1 and 0

    double chance = rand() % 1000000;
    chance = chance / 1000000.0;
    if ((sex.compare("male") == 0 && chance <= mprob) || (sex.compare("female") == 0 && chance <= fprob)) {
      alive = false;
    } else {
      age++;
      getline(f, line);
      if (age >= 120) {
        alive = false;
      }
    }
  }
  f.close();
  return age;
}

int main() {
  // initialize
  int age;
  string sex;

  // get age and validate
  cout << "Enter an age between 0 and 119: ";
  cin >> age;
  if (age >= 120 || age < 0) {
    cout << "invalid age.";
    return 0;
  }

  // get sex and validate
  cout << "Enter a sex [male/female]: ";
  cin >> sex;
  if (sex.compare("male") != 0 && sex.compare("female") != 0) {
    cout << "invalid sex.";
    return 0;
  }

  // start simulation
  cout << "\n";
  int finalage = simulate(age, sex);
  cout << "They lived to be " << finalage << " years old.";

}
