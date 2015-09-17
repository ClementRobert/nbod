#compil notes.html
markdown notes.md > notes.html

WID=`xdotool search --name "Mozilla Firefox" | head -1`
xdotool windowactivate $WID
xdotool key F5
#manque possibilité que l'onglet actif ne soit pas celui qui nous interesse ou que le fichier notes.html ne soit même pas ouvert
#il faudrait aussi que ce script n'ai pas le défaut de faire passer firefox en application active au détrimant du terminal



#instalation des fichiers recquis pour faire tourner ce script sous ubuntu

# sudo apt-get install aptitude
# sudo aptitude install xdotool

# WID=`xdotool search --title "Mozilla Firefox" | head -1`
# xdotool windowactivate $WID
# xdotool key F5
