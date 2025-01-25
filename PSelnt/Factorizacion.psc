// Revisado por: Dulce Rocio Reyes pirir 9959-24-684 

Algoritmo Factorizacion
	
	Escribir "Ingrese el numero: "
	Leer num
	
	Escribir "Factorizacion: "
	
	factorizar<-verdadero
	
	Mientras factorizar & num>1 hacer
		div<-0
		Si num/2 = trunc(num/2) Entonces
			Escribir 2
			num<-num/2
		SiNo
			div<-1; factor_primo<-Verdadero
			Mientras div<=rc(num) & factor_primo Hacer
				div <- div+2
				Si num/div = trunc(num/div) Entonces
					factor_primo <- Falso
				FinSi
			FinMientras
			Si factor_primo Entonces
				escribir num
				factorizar<-falso
			sino
				escribir div
				num<-num/div
				factor_primo<-verdadero
			FinSi
		FinSi
	FinMientras
	
FinAlgoritmo