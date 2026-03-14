#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

 struct etudiant
    {
        string nom;
        int age;
        float moyenne;
    };
    
int main()
{
   vector<etudiant> etudiants;

    int choix;
    while (choix<6)
    {
        cout<<"Miarahaba anao Tompoko !!!:\n";
        cout<<"1- Ajouter un étudiant"<<endl;
        cout<<"2- Afficher les étudiants"<<endl;
        cout<<"3- Trier leurs moyennes par ordre decroissant"<<endl;
        cout<<"4- Rechercher un étudiant par nom"<<endl;
        cout<<"5- Supprimer un étudiant par nom"<<endl;
        cout<<"6- Quitter"<<endl;
        cin>>choix;

        switch (choix)
        {
            case 1:
                {
                    etudiant e;
                    cout<<"AJOUT ETUDIANT:"<<endl;
                    cout << "-------------------" << endl;
                    cout<<"Entrez le nom de l'étudiant: ";
                    cin>>e.nom;
                    cout<<"Entrez l'âge de l'étudiant: ";
                    cin>>e.age;
                    cout<<"Entrez la moyenne de l'étudiant: ";
                    cin>>e.moyenne;
                    etudiants.push_back(e);
                    break;
                }
            case 2:
                {
                    cout << "Liste des étudiants:" << endl;
                    for (const auto& e : etudiants) {
                        cout << "Nom: " << e.nom << ", Age: " << e.age << ", Moyenne: " << e.moyenne << endl;
                    }
                    break;
                }
            case 3:
                {
                    sort(etudiants.begin(), etudiants.end(), [](const etudiant& a, const etudiant& b) {
                        return a.moyenne > b.moyenne;
                    });
                    cout << "Étudiants triés par moyenne décroissante." << endl;
                    break;
                }
            case 4:
                {
                    string nomRecherche;
                    cout<<"Entrez le nom de l'étudiant à rechercher: ";
                    cin>>nomRecherche;
                    bool trouve = false;
                    for (const auto& e : etudiants) {
                        if (e.nom == nomRecherche) {
                            cout << "Étudiant trouvé:\n Nom: " << e.nom << "\n Age: " << e.age << "\n Moyenne: " << e.moyenne << endl;
                            trouve = true;
                            break;
                        }
                    }
                    if (!trouve) {
                        cout << "Étudiant non trouvé." << endl;
                    }
                    break;
                }
            case 5:
                {
                    string nomSupprimer;
                    cout<<"Entrez le nom de l'étudiant à supprimer: ";
                    cin>>nomSupprimer;
                    auto it = remove_if(etudiants.begin(), etudiants.end(),
                                         [&nomSupprimer](const etudiant& e) {
                                             return e.nom == nomSupprimer;
                                         });
                    etudiants.erase(it, etudiants.end());
                    cout << "Étudiant supprimé." << endl;
                    break;
                }
            case 6:
                {
                    cout << "Au revoir!" << endl;
                    break;
                }
        }
    }

    return 0;
}
    /*// Ajouter des étudiants à la liste
    etudiants.push_back({"Alice", 20, 15.5});
    etudiants.push_back({"Bob", 22, 12.0});
    etudiants.push_back({"Charlie", 19, 18.0});

    // Trier les étudiants par moyenne décroissante
    sort(etudiants.begin(), etudiants.end(), [](const etudiant& a, const etudiant& b) {
        return a.moyenne > b.moyenne;
    });

    // Afficher les étudiants triés
    cout << "Liste des étudiants triés par moyenne décroissante:" << endl;
    for (const auto& e : etudiants) {
        cout << "Nom: " << e.nom << ", Age: " << e.age << ", Moyenne: " << e.moyenne << endl;
    }

    return 0;//*/

