#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

    struct etudiant
        {
            int index;
            string nom;
            int age;
            double moyenne;
        };

        void ajouterEtudiant(vector<etudiant>& list){
        etudiant e;
        static int compteurID = 1;
        e.index = compteurID++;
        cout<<"AJOUT ETUDIANT:"<<endl;
        cout << "-------------------" << endl;
        cout<<": \n";
        cout<<"======  Index number: "<<e.index<<"  ======="<<endl;
        cin>>e.nom;
        cout<<"Entrez l'âge de l'étudiant: ";
        cin>>e.age;
        cout<<"Entrez la moyenne de l'étudiant: ";
        cin>>e.moyenne;
        list.push_back(e);
        cout<<"Étudiant ajouté avec succès!\n son ID =   "<<e.index<<endl;
    }

    void afficherEtudiants(const vector<etudiant>& list){
        cout << "Liste des étudiants:" << endl;
        for (const auto& e : list) {
            cout << "ID number: " << e.index << " | Nom: " << e.nom << ", Age: " << e.age << ", Moyenne: " << e.moyenne << endl;
        }
    }

    void trierEtudiantsParMoyenne(vector<etudiant>& list){
        if (list.empty())
        {
            cout << "La liste des étudiants est vide." << endl;
            return;
        }
        
        sort(list.begin(), list.end(), [](const etudiant& a, const etudiant& b) {
            return a.moyenne > b.moyenne;
        });
        cout << "Étudiants triés par moyenne décroissante." << endl;
        for (size_t i = 0; i < list.size(); i++)
        {
            cout << i + 1 << ". ID: " << list[i].index << " | Nom: " << list[i].nom << ", Age: " << list[i].age << ", Moyenne: " << list[i].moyenne << endl;
        }
        
    }   
    void rechercherEtudiantParNom(const vector<etudiant>& list){
        string nomRecherche;
        cout<<"Entrez le nom de l'étudiant à rechercher: ";
        cin>>nomRecherche;
        bool trouve = false;
        for (const auto& e : list) {
            if (e.nom == nomRecherche) {
                cout << "Étudiant trouvé:\n Nom: " << e.nom << "\n Age: " << e.age << "\n Moyenne: " << e.moyenne << endl;
                trouve = true;
                break;
            }
        }
        if (!trouve) {
            cout << "Étudiant non trouvé." << endl;
        }
    }
    void supprimerEtudiantParNom(vector<etudiant>& list){
        string nomSupprimer;
        cout<<"Entrez le nom de l'étudiant à supprimer: ";
        cin>>nomSupprimer;
        /*auto it = remove_if(list.begin(), list.end(),
                             [&nomSupprimer](const etudiant& e) {
                                 return e.nom == nomSupprimer;
                             });
        if (it != list.end()) {
            list.erase(it, list.end());
            cout << "Étudiant supprimé avec succès." << endl;
        } else {
            cout << "Étudiant non trouvé." << endl;
        }*/
       for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->nom == nomSupprimer) {
                list.erase(it);
                cout << "\nÉtudiant " << nomSupprimer << ": supprimé avec succès." << endl;
                return;
            }
         }
        cout << "Étudiant non trouvé." << endl;
       
    }

int main(){
    vector<etudiant> list;

    int c;
    while (c<6)
    {
        cout<< "\n\n Bienvenue dans le programme de gestion des étudiants !!!:\n";
        cout<<"-------------------------------------------------------------------------------------"<<endl;
        cout<< "Menu:\n";
        cout<<"======\n";
        cout<<"1- Ajouter un étudiant"<<endl;
        cout<<"2- Afficher les étudiants"<<endl;
        cout<<"3- Trier leurs moyennes par ordre decroissant"<<endl;
        cout<<"4- Rechercher un étudiant par nom"<<endl;
        cout<<"5- Supprimer un étudiant par nom"<<endl;
        cout<<"6- Quitter"<<endl;
        cout<<"-------------------------------------------------------------------------------------"<<endl;
        cout<<"Veuillez choisir une option: ";
        cin>>c;

        switch (c)
        {
            case 1:
            {
                ajouterEtudiant(list);
                
            } break;
            case 2:
            {
                afficherEtudiants(list);
            } break;
            case 3:
            {
                trierEtudiantsParMoyenne(list);
            } break;
            case 4:
            {
                rechercherEtudiantParNom(list);
            } break;
            case 5:
            {
                supprimerEtudiantParNom(list);
            } break;
            case 6:
            {
                cout<<"Merci d'avoir utilisé le programme de gestion des étudiants. Au revoir!"<<endl;
            } break;
            default:
            {
                cout<<"Option invalide. Veuillez choisir une option valide."<<endl;
            } break;
        }
      
    }


return 0;
    
}