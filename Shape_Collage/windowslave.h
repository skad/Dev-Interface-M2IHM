#ifndef WINDOWSLAVE_H
#define WINDOWSLAVE_H
#include"convertisseur.h"
#include<QLineEdit>
#include<QPushButton>
#include"grillephotos.h"
#include<QWidget>
#include<QLabel>
#include<QDebug>
#include<QFileDialog>
#include<QColorDialog>
#include<QMessageBox>
#include<QRadioButton>
#include<QComboBox>
#include<QLineEdit>
#include <QPoint>
#include <QVector>
#include <QSpinBox>
#include "labeldessinable.h"
#include"dialogdessinformeextra.h"
#include"labelclicable.h"
#include"parameters.h"

#include <QDesktopServices>

#define PI 3.141592653
/**
 * \brief Cette classe fournis, exclusivement, des services spécifiques à la fenetre principale et ses composants
 */
class WindowSlave
{
public:
    WindowSlave();

    /**
     * \brief Convertis la valeur du text d'un QLineEdit au format de la valeur d'un index vers le format d'un de la valeur d'un autre index
     * \a index index du format vers lequel la la valeur du text du QLineEdit sera convertis
     * \a oldindex index du format actuel de la valeur à convertir
     * \a lineedit Champ de text (QLineEdit) dont la valeur sera convertie
     */
    static void ConvertAndMAJLineEdit(int index, int &oldindex, QLineEdit *lineedit);

    /**
     * \brief Ajoute une image a un champ GrillePhotos et met à jour les champs qui lui sont associés
     * \a g GrillePhotos dans laquelle l'image est ajoutée
     * \a moins Bouton de suppression d'images selectionnées dans la grille
     * \a clear Bouton de suppression de toutes les images de la grille
     * \a l label affichant le nombre d'images contenues dans la grille
     */
    static void AjouterImage(GrillePhotos* g, QPushButton* moins, QPushButton *clear, QLabel* l);

    /**
     * \brief Retire une image d'un champ GrillePhotos et met à jour les champs qui lui sont associés
     * \a g GrillePhotos de laquelle l'image est retirée
     * \a moins Bouton de suppression d'images selectionnées dans la grille
     * \a clear Bouton de suppression de toutes les images de la grille
     * \a l label affichant le nombre d'images contenues dans la grille
     */
    static void RetirerImage(GrillePhotos* g, QPushButton* moins, QPushButton *clear, QLabel* l);

    /**
     * \brief supprime toutes les images d'une GrillePhotos et met à jour les champs associés
     * \a g GrillePhotos dont on supprime les image
     * \a moins Bouton de suppression d'images selectionnées dans la grille
     * \a clear Bouton de suppression de toutes les images de la grille
     * \a l label affichant le nombre d'images contenues dans la grille
     */
    static void ViderGrillePhoto(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel* l);

    /**
     * \brief supprime toutes les images d'une GrillePhotos et met à jour les champs associés après validation d'une boite de dialogue
     * \a g GrillePhotos dont on supprime les image
     * \a moins Bouton de suppression d'images selectionnées dans la grille
     * \a clear Bouton de suppression de toutes les images de la grille
     * \a l label affichant le nombre d'images contenues dans la grille
     */
    static void EffacerListePhoto(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel *l);

    /**
     * \brief Change le text d'un bouton selon la valeur d'un booleen ("Manuel" pour vrai et "Auto" pour faux) et met à jour son statustip
     * \a value booleen à tester
     * \a bouton bouton dont le text est changé
     * \a section nom de la section à laquelle le bouton appartient
     */
    static void SetTextBouton(bool value, QPushButton *bouton, const QString &section);

    /**
     * \brief Grise ou dégrise les éléments d'un tableau de QWidget selon un booleen
     * \a mode booleen selon lequel les champs seront grisés ou non
     * \a boutonMode bouton de la section traitée
     * \a section nom de la section à laquelle appartiennent les champs traités
     * \a groupe Tableau de QWidget à grisé ou dégrisé
     * \a nb nombre d'élément du tableau \a groupe
     */
    static void GriseOuDegriseGroupe(bool &mode, QPushButton *boutonMode, const QString &section, QWidget * *groupe, int nb);

    /**
     * \brief Change la couleur d'un LabelClicable et retourne la couleur courante de ce label
     * \a label label à modifier
     * \return La couleur actuelle du LabelClicable \a label
     */
    static QColor ChangerCouleurArrierePlan(LabelClicable* label);

    /**
     * \brief Change l'arriere-plan d'un LabelClicable avec une image
     * \a label le label dont l'arriere plan est changé
     * \a lienPhoto lien de l'image à afficher
     */
    static void ChargerPhotoArrierePlan(LabelClicable* label,QString& lienPhoto, QLineEdit* leWidth = 0, QLineEdit* leHeight = 0);

    /**
     * @brief ChangerPhotoArrierePlan Change la photo d'arrière-plan
     * @param label Label contenant l'arrière-plan
     * @param fichier Chemin vers l'image d'arrière-plan
     * @param lineEditWidth Widget contenant la taille de l'image (largeur)
     * @param lineEditHeigh Widget content la taille de l'image (hauteur)
     */
    static void ChangerPhotoArrierePlan(LabelClicable* label, QString &fichier, QLineEdit* lineEditWidth, QLineEdit* lineEditHeigh);

    /**
     * @brief AskCollageSizeToBackgroundAdjustement Affiche un dialog demandant à l'utilisateur s'il désire ajuster la taille du collage à celui de la photo d'arrière plan
     */
    static bool AskCollageSizeToBackgroundAdjustement();

    /**
     * @brief AdjustCollageSizeToBackground Ajuste la taille du collage
     *
     */
    static void AdjustCollageSize(QLineEdit* lineEditWidth, QLineEdit* lineEditHeight, int width, int height);

    static int DessinerForme(LabelDessinable*&);

    /**
     * \brief Teste si un fichier est une image
     * \a fichier fichier à tester
     * \return vrai si \a fichier est une image et faux sinon
     */
    static bool EstUneImage(QString& fichier);

    /**
     * \brief showSuccessDialog Affiche un dialogue confirmant l'enregistrement du collage
     */
    static void showSuccessDialog();
    /**
     * \brief showFailureDialog Affiche un message d'erreur
     * \a Le message d'erreur
     */
    static void showFailureDialog(QString);
    /**
     * \brief Remet toutes les valeurs par défaut en vue de créer un nouveau projet
     * \a radioRectangle bouton radio correspondant à la forme rectangle sur l'UI
     * \a comboTaillecollage combobox d'unité de mesure d'affichage de la taille du collage
     * \a champ de texte de saisie de la largeur largeur du collage
     * \a champ de texte de saisie de la hauteur hauteur du collage
     * \a comboTaillePhoto combobox d'unité de mesure d'affichage de la taille de la photo
     * \a taillePhoto taille de la photo
     * \a tout bouton radio de selection de toutes les photos pour le collage
     * \a nbPhoto champ de texte de saisie du nombre de photos utilisées pour le collage
     * \a distance slider pour modifier la distance entre les photos
     * \a arrierePlan bouton radio de selection du style de l'arriere-plan
     * \a couleur label de selection de la couleur de l'arrière-plan
     */
    static void RemettreValeursParDefaut(QRadioButton* radioRectangle,QComboBox *comboTaillecollage,
                                         QLineEdit* largeur,QLineEdit* hauteur,QComboBox* comboTaillePhoto,
                                         QLineEdit* taillePhoto,QRadioButton* tout,QLineEdit* nbPhoto,
                                         QSlider* distance,QRadioButton* arrierePlan,LabelClicable* couleur, LabelDessinable* preview, LabelClicable* photoBackground);

    /**
     * @brief Converti les valeurs fournies en hauteur et largeur en QSize pour la classe parametre
     * @param modeValeur int represetant le type de valeur (0 pixels / 1 inch / 2 cm
     * @param largeur QlineEdit contenant la valeur de largeur
     * @param hauteur QlineEdit contenant la valeur de hauteur
     * @return QSize taille utilisable dans la classe Davinci
     */
    static QSize SizeUiToParam(int modeValeur ,QLineEdit* largeur ,QLineEdit* hauteur);

    /**
     * @brief Converti la valeur fournie en size en double pour la classe parametre
     * @param modeValeur int represetant le type de valeur (0 pixels / 1 inch / 2 cm
     * @param size QlineEdit contenant la valeur de la taille
     * @return double taille utilisable dans la classe Davinci
     */
    static int PhotoSizeUiToParam(int modeValeur ,QLineEdit* size);

    /**
     * @brief Converti le nombre de photo de l'ui en parametre
     * @param nbphotolist Nombre de photo dans la GrillePhotos
     * @param radiobuttonphoto QRadioRutton  indiquant le choix de l'utilisateur
     * @param lideeditbutton QLineEdit contenant la valeur manuelle demandée par l'utilisateur
     * @return le nombre de photomax
     */
        static int NbPhotoUiToParam(int nbphotolist,QRadioButton* radiobuttonphoto, QLineEdit* lideeditbutton);

    /**
     * @brief Recupere la valeur dans la SpinBox passée en parametre \a spinsize et la transofrme en int
     * @param spinsize QSpinBox contenant la valeur
     * @return valeur
     */
     static int DistancePhotoUItoParam(QSpinBox* spinsize);

     /**
      * @brief Resort la bonne ColageForm pour les parametre en fonction des radiobuttons
      * @param extra RadioButton pour la forme Extra
      * @param cercle RadioButton pour la forme Cercle
      * @return CollageForm
      */
     static CollageForm FormUIToParam(QRadioButton* extra, QRadioButton* cercle);

     /**
      * @brief Resort la bonne pixmap pour le parametre de background
      * @param radiocolor Radiobouton pour la couleur
      * @param color Qcolor
      * @param radiotransparent Radiobouton pour le transparent
      * @param lienPhoto Url de la photo
      * @return La QPixmap generée
      */
     static QPixmap BackgroundUiToParam(QRadioButton* radiocolor,QColor color,QRadioButton* radiotransparent,QString lienPhoto);

     /**
      * @brief ResizeToFit Redimensionne une pixmap pour tenir dans un label
      * @param pixmap La pixmap à redimensionner
      * @param label Le label dans lequel la pixmap doit tenir
      * @return La pixmap redimensionnée
      */
     static QPixmap ResizeToFit(QPixmap& pixmap, QLabel* label);
};

#endif // WINDOWSLAVE_H
