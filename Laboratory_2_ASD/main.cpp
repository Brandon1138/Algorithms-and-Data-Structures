/* Fisier: arbori_ptlab.cpp
 * Programul creaza un arbore binar, il tipareste si calculeaza
 * numarul de noduri. Foloseste reprezentarea inlantuita a unui arbore.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

struct NodArb
{
    int info;
    NodArb *stang;
    NodArb *drept;
    };

//typedef struct NodArb* NodArbPtr;

NodArb* creaza_arbore();

void tiparire_arbore(NodArb *rad);

void inordine(NodArb *rad)
{
    if (rad != NULL)
    {
        inordine(rad->stang);
        cout << rad ->info << " ";
        inordine(rad -> drept);
    }
}

void preordine(NodArb *rad)
{
    if (rad != NULL)
    {
        cout << rad ->info << " ";
        preordine(rad->stang);
        preordine(rad -> drept);
    }
}

void postordine(NodArb *rad)
{
    if (rad != NULL)
    {
        postordine(rad->stang);
        postordine(rad->drept);
        cout << rad->info << " ";
    }
}

int nr_noduri (NodArb *rad)
{
    if (rad != NULL)
    return nr_noduri(rad->stang) + nr_noduri(rad->drept) + 1;
    else return 0;
}

int nr_frunze(NodArb *rad)
{
    if (rad == NULL)
        return 0;
    if (rad->stang == NULL && rad->drept == NULL)
        return 1;
    else
        return nr_frunze(rad->stang) + nr_frunze(rad->drept);
}

int inaltime_arbore(NodArb *rad)
{
    if (rad == NULL)
        return 0;
    else
    {
        int inaltime_stanga = inaltime_arbore(rad->stang);
        int inaltime_dreapta = inaltime_arbore(rad->drept);
        if (inaltime_stanga > inaltime_dreapta)
            return(inaltime_stanga + 1);
        else return(inaltime_dreapta + 1);
    }
}

 int main()
{
  NodArb* rad=NULL;
  cout << "Construim arborele...\n";
  rad = creaza_arbore();
  cout << "\n\nTiparire arbore\n\n";
  tiparire_arbore(rad);
  cout << endl << endl;

  cout << "INORDINE: ";
  inordine(rad);
  cout << endl;
  cout << "PREORDINE: ";
  preordine(rad);
  cout << endl;
  cout << "POSTORDINE: ";
  postordine(rad);
  cout << endl;

  cout << "Numarul de noduri este: " << nr_noduri(rad) << endl;

  cout << "Numarul de frunze este: " << nr_frunze(rad) << endl;

  cout << "Inaltimea arborelui este: " << inaltime_arbore(rad) << endl;

  return 0;
  }

NodArb* creaza_arbore()
{
   NodArb* rad;
   char c;
   cout << "Introduceti un nod (Y/N)? ";
  // rewind(stdin);
   cin >> c;
   if(c=='y'||c=='Y')
   {
   rad = new  NodArb;
   cout << "Info radacina: ";
   cin >> rad -> info;
   cout << "\nNodul stang al lui " << rad -> info <<endl;
   rad -> stang = creaza_arbore();
   cout << "\nNodul drept al lui " << rad -> info <<endl;
   rad -> drept = creaza_arbore();
   }
   else rad=NULL;
   return rad;
}

void tiparire_arbore(NodArb* rad)
{
   if(rad==NULL)
   cout << "NULL\n";
   else
   {
       cout << "rad = " << rad ->info << endl;
       cout << "Subarbore stang al lui  " << rad -> info << endl;
       tiparire_arbore(rad -> stang);
       cout << "Subarbore drept al lui " << rad -> info << endl;
       tiparire_arbore(rad -> drept);
       }
}
