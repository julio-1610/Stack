# Lista Enlazada

Esta es una estructura de datos donde vemos una lista de datos enlazado de manera circular.

## Atributos
```
 - Lista: estructura
 - Nodos: Atributo principal de la Lista que se conectan entre sí.
 - Dato: elemento del propio.
```

## Funciones
```
 - new: 					--> Lista
 - append: Dato 	--> Lista
 - head:   				--> Dato
 - size:					--> INT
 - isEmpty:				--> BOOl
 - index: 				--> Lista
```

## Axiomas
```
 - size(new) == 0
 - size(append(Dato)) > 0
 - size(append(new, Dato)) == 1
 - empty(new) == True
 - empty(append(Dato)) == False
 - head(new) = error/undefined
 - head(append(new, Dato)) == Dato
```

# Stack

Estructura de datos guarda de manera secuencial los datos, y solo se acceden a los datos que se ingresaron ultimamente.  

## Types
```
 - S: STACK
 - E, F: ELEMENT
```
## Funciones
```
 - new     :          -->  STACK 
 - push		 : E				-->  STACK
 - pop     : STACK		-->  STACK
 - top 		 : STACK 		-->  ELEMENT
 - empty   : STACK 		-->  BOOL
 ```
## Axiomas
```
 - pop(new)				= S
 - pop(push(E))		= S
 - top(new)				= undefined
 - top(push(E))   = E
 - empty(new)  		= TRUE
 - empty(push(E)) = FALSE
```
