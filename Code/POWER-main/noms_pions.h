#ifndef NOMS_PIONS_H_INCLUDED
#define NOMS_PIONS_H_INCLUDED

 static const char * nom_type_pions[taille_enum_pion]= {"Chasseur", //chasseur
                                                        "Destroyeur", //destroyer
                                                        "Bombardier", //bombardier DEJA GROUPE 2
                                                        "Croiseur", //croiseur DEJA GROUPE 2
                                                        "Soldat", //soldat
                                                        "Tank", //tank
                                                        "Char", //char DEJA GROUPE 2
                                                        "Mega-missile", //megamissile -> non applicable
                                                        "Regiment", //regiment DEJA GROUPE 2
                                                        "[PIECE_INEXISTANTE]", //inexstante -> non applicable
                                                        }; //static const : on definit le tableau d'enum comme un define qui ne bouge plus


#endif // NOMS_PIONS_H_INCLUDED
