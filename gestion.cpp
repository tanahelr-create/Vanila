#include <iostream>   // Permet d'utiliser cout et cin (affichage et saisie)
#include <vector>     // Permet d'utiliser vector (tableau dynamique)
#include <string>     // Permet d'utiliser le type string
#include <limits>     // Permet d'utiliser numeric_limits pour vider le buffer

using namespace std;  // Pour éviter d'écrire std::cout, std::cin etc.

// Création d'une structure pour représenter un étudiant
struct Etudiant {
    int numero;       // Numéro de l'étudiant
    string nom;       // Nom de l'étudiant
    double moyenne;   // Moyenne de l'étudiant
};

// Fonction pour afficher le menu
void menu() {
    cout << "\n===== Gestion des étudiants =====\n";
    cout << "1. Ajouter un étudiant\n";
    cout << "2. Afficher la liste des étudiants\n";
    cout << "3. Rechercher un étudiant par son numéro\n";
    cout << "4. Calculer la moyenne générale de la classe\n";
    cout << "5. Quitter\n";
    cout << "Votre choix : ";
}

// Fonction pour faire une pause (attendre que l'utilisateur appuie sur Entrée)
void attendreAppuiTouche() {
    cout << "\nAppuyez sur Entrée pour continuer...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vide le buffer
    cin.get(); // attend que l'utilisateur appuie sur Entrée
}

// Fonction pour ajouter un étudiant dans le vector
void ajouterEtudiant(vector<Etudiant>& etudiants) {

    Etudiant e;  // création d'une variable étudiant

    cout << "\n--- Ajouter un étudiant ---\n";

    cout << "Numéro : ";
    cin >> e.numero; // saisie du numéro

    // vider le buffer pour pouvoir utiliser getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nom : ";
    getline(cin, e.nom); // saisie du nom complet

    cout << "Moyenne : ";
    cin >> e.moyenne; // saisie de la moyenne

    // Ajouter l'étudiant dans le vector
    etudiants.push_back(e);

    cout << "Etudiant ajouté avec succès !\n";
}

// Fonction pour afficher tous les étudiants
void afficherListe(const vector<Etudiant>& etudiants) {

    // vérifier si la liste est vide
    if (etudiants.empty()) {
        cout << "\nAucun étudiant dans la liste.\n";
        return;
    }

    cout << "\n--- Liste des étudiants ---\n";

    // boucle pour parcourir le vector
    for (size_t i = 0; i < etudiants.size(); i++) {

        cout << "Numéro : " << etudiants[i].numero
             << " | Nom : " << etudiants[i].nom
             << " | Moyenne : " << etudiants[i].moyenne
             << endl;
    }
}

// Fonction pour rechercher un étudiant par son numéro
void rechercherEtudiant(const vector<Etudiant>& etudiants) {

    int num;

    cout << "\nEntrez le numéro de l'étudiant à rechercher : ";
    cin >> num;

    // parcourir le vector
    for (size_t i = 0; i < etudiants.size(); i++) {

        // vérifier si le numéro correspond
        if (etudiants[i].numero == num) {

            cout << "\nEtudiant trouvé :\n";
            cout << "Numéro : " << etudiants[i].numero << endl;
            cout << "Nom : " << etudiants[i].nom << endl;
            cout << "Moyenne : " << etudiants[i].moyenne << endl;

            return; // arrêter la fonction
        }
    }

    // si aucun étudiant trouvé
    cout << "Aucun étudiant avec ce numéro.\n";
}

// Fonction pour calculer la moyenne générale de la classe
void moyenneGenerale(const vector<Etudiant>& etudiants) {

    if (etudiants.empty()) {
        cout << "\nAucun étudiant pour calculer la moyenne.\n";
        return;
    }

    double somme = 0.0; // variable pour stocker la somme des moyennes

    // parcourir les étudiants
    for (size_t i = 0; i < etudiants.size(); i++) {

        somme += etudiants[i].moyenne; // ajouter chaque moyenne
    }

    // calcul de la moyenne générale
    double moyenne = somme / etudiants.size();

    cout << "\nLa moyenne générale de la classe est : " << moyenne << endl;
}

// Fonction principale
int main() {

    vector<Etudiant> etudiants; // vector qui stocke tous les étudiants
    int choix = 0;              // variable pour stocker le choix du menu

    // boucle principale du programme
    while (choix != 5) {

        menu(); // afficher le menu

        cin >> choix; // lire le choix de l'utilisateur

        switch (choix) {

            case 1:
                ajouterEtudiant(etudiants);
                attendreAppuiTouche();
                break;

            case 2:
                afficherListe(etudiants);
                attendreAppuiTouche();
                break;

            case 3:
                rechercherEtudiant(etudiants);
                attendreAppuiTouche();
                break;

            case 4:
                moyenneGenerale(etudiants);
                attendreAppuiTouche();
                break;

            case 5:
                cout << "\nAu revoir !\n";
                break;

            default:
                cout << "Choix invalide !\n";
        }
    }

    return 0; // fin du programme
}
