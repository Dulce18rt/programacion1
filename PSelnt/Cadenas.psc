// Revisado Por:  Dulce Rocio Reyes Pirir  9959-24-684 
// Este ejemplo muestra como utilizar las funciones para manejo 
// de cadenas de caracteres. Requiere que el perfil de lenguaje
// habilite estas funciones. Si al intentar ejecutar obtiene
// errores en las funciones, revise su configuración en el
// item "Opciones del lenguaje" del menú "Configurar".
Algoritmo cadenas
	// el usuario ingresa una frase, vamos a contar cuantas vocales tiene
	Escribir 'Ingrese una frase'
	Leer frase
	// pasamos toda la frase a minusculas para no tener que preguntar 2 veces por cada vocal
	frase <- Minusculas(frase)
	// lista de letras que vamos a buscar
	vocales <- 'aeiouáéíóúü'
	cantVocales <- 0
	// comparar todas las letras de frase con las de vocales y contar coincidencias
	Para i<-1 Hasta Longitud(frase) Hacer
		Para j<-1 Hasta Longitud(vocales) Hacer
			Si Subcadena(frase,i,i)=Subcadena(vocales,j,j) Entonces
				cantVocales <- cantVocales+1
			FinSi
		FinPara
	FinPara
	Escribir 'La frase contiene ', cantVocales, ' vocales.'
FinAlgoritmo
