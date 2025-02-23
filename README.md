# cryptography

## Beaufort Cipher
Le chiffre de Beaufort est un système de chiffrement par substitution. Pour utiliser cette méthode,  
l'utilisateur va devoir encoder le message ainsi qu'une clé de chiffrement. Dans le cas où la clé de  
chiffrement est plus petite que le texte à chiffrer, celle-ci est alors répétée pour obtenir la taille  
correspondante.  

_Exemple : La clé « EXAMEN » va être utilisée pour chiffrer la chaîne « LABORATOIRES »  
La clé deviendra donc : « EXAMENEXAMEN »_  

La méthode de chiffrement (et de déchiffrement) consiste alors à soustraire chaque lettre du texte  
clair à la lettre de la clé correspondante (grâce à leur position dans l'alphabet avec A = 0) On  
utilisera « ABCDFEGHIJKLMNOPQRSTUVWXYZ » comme alphabet.  

_Exemple : Pour chiffrer L on fera E - L = T. On obtiendra pour l'exemple « TXZYNNLJSVAV »  
Pour déchiffrer on fera E - T = L._  

Le programme doit également comparer la lettre la plus fréquente dans le message en clair avec celle la plus  
fréquente dans le message chiffré.  

**main()**  
**{**  
**// déclaration du tableau destiné à contenir le message en clair**  
**// déclaration du tableau destiné à contenir la clé**
**// appel de la procédure d'encodage du message (en majuscule)**  

**// appel de la procédure d'encodage de la clé (en majuscule)**  
**// appel de la procédure de répétition de la clé**  

**// appel de la procédure de chiffrement/déchiffrement**  
**// appel de la fonction de détermination de la lettre qui apparaît le plus souvent dans le message en clair**  
**// appel de la fonction de détermination de la lettre qui apparaît le plus souvent dans le message chiffré**  

**}**


