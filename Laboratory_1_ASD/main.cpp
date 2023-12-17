#include<iostream>
using namespace std;

int lista[100];
int N;

void introducere(int val, int poz) {
    if(poz >= N) {
        cout << "Pozitia este in afara limitei.\n";
        return;
    }
    lista[poz] = val;
}

void stergere(int poz) {
    if(poz >= N) {
        cout << "Pozitia este in afara limitei. \n";
        return;
    }
    for(int i = poz; i < N-1; i++)
        lista[i] = lista[i+1];
    N--;
}

void accesare(int poz) {
    if(poz >= N) {
        cout << "Pozitia este in afara limitei. \n";
        return;
    }
    cout << "Elementul de pe pozitia " << poz << " este: " << lista[poz] << endl;
}

void modificare(int poz, int val) {
    if(poz >= N) {
        cout << "Pozitia este in afara limitei. \n";
        return;
    }
    lista[poz] = val;
}

void creare_lista() {
    cout << "Cate elemente va avea lista? ";
    cin >> N;
    for(int i = 0; i < N; i++) {
        cout << "Elementul " << i << ": ";
        cin >> lista[i];
    }
}

void afisare_lista() {
    for(int i = 0; i < N; i++)
        cout << lista[i] << " ";
    cout << endl;
}

int main() {
    int opt, val, poz;

    while(true) {
        cout << "1. Introducere element\n";
        cout << "2. Stergere element\n";
        cout << "3. Accesare element\n";
        cout << "4. Modificare element\n";
        cout << "5. Creare lista\n";
        cout << "6. Afisare lista\n";
        cout << "7. Exit\n";
        cout << "Alege optiunea: ";
        cin >> opt;

        switch(opt) {
            case 1:
                cout << "Valoarea: ";
                cin >> val;
                cout << "Pozitia: ";
                cin >> poz;
                introducere(val, poz);
                break;
            case 2:
                cout << "Pozitia: ";
                cin >> poz;
                stergere(poz);
                break;
            case 3:
                cout << "Pozitia: ";
                cin >> poz;
                accesare(poz);
                break;
            case 4:
                cout << "Pozitia: ";
                cin >> poz;
                cout << "Valoarea: ";
                cin >> val;
                modificare(poz, val);
                break;
            case 5:
                creare_lista();
                break;
            case 6:
                afisare_lista();
                break;
            case 7:
                return 0;
            default:
                cout << "Optiune invalida!\n";
                break;

        }
    }

    return 0;
}