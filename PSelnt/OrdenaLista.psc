// Revisado por: Dulce Rocio Reyes Pirir  9959-24-684
// Se ingresa una lista de nombres (la lista termina
// cuando se ingresa un nombre en blanco) no permitiendo
// ingresar repetidos y luego se ordena y muestra
Algoritmo OrdenaLista
	Dimensionar lista(200)
	Escribir 'Ingrese los nombres (enter en blanco para terminar):'
	// leer la lista
	cant <- 0
	Leer nombre
	Mientras nombre<>'' Hacer
		cant <- cant+1
		lista[cant] <- nombre
		Repetir
			Leer nombre // leer un nombre y ver que no este ya en la lista
			se_repite <- Falso
			Para i<-1 Hasta cant Hacer
				Si nombre=lista[i] Entonces
					se_repite <- Verdadero
				FinSi
			FinPara
		Hasta Que  NO se_repite
	FinMientras
	// ordenar
	Para i<-1 Hasta cant-1 Hacer
		// busca el menor entre i y cant
		pos_menor <- i
		Para j<-i+1 Hasta cant Hacer
			Si lista[j]<lista[pos_menor] Entonces
				pos_menor <- j
			FinSi
		FinPara
		// intercambia el que estaba en i con el menor que encontro
		aux <- lista[i]
		lista[i] <- lista[pos_menor]
		lista[pos_menor] <- aux
	FinPara
	// mostrar como queda la lista
	Escribir 'La lista ordenada es:'
	Para i<-1 Hasta cant Hacer
		Escribir '   ', lista[i]
	FinPara
FinAlgoritmo
