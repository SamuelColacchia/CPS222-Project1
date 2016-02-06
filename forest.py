#import random
import random

#simulae the forest by first making the forest with a boarder then
#then applying the probablilities in for loops, and finaly reapinting the forest.
def simulate (cycles,width,height,pInit,pFire,pLocl,pDist):
  forest = makeEmptyPicture(width,height)
  createForest(width,height,forest,pInit)
  #for loop that cycles through the simulation
  #a given number of times.
  for cycle in range(0,cycles):
    pic2 = duplicatePicture(forest)
    
    #loops through the entire forest.
    for x in range(1, getWidth(forest) - 1):
      for y in range(1, getHeight(forest) - 1):
        pixColor = getColor(getPixel(forest,x,y))
        
        #simulayes growth and death of the forest.
        if pixColor == green and catchingFire(pic2,x,y):
          setColor (getPixel(forest,x,y), red)
        elif pixColor == green: 
          if random.random() < pFire:
            setColor (getPixel(forest,x,y), red)
        elif pixColor == red:
          setColor (getPixel(forest,x,y), white)
        elif pixColor == white:
          numTrees = countTrees(pic2,x,y)
          if random.random() <  pDist + pLocl * numTrees:
            setColor(getPixel(forest,x,y),green)
          
    repaint(forest)
    
    
def createForest(width,height,pic1,pInit):
  for x in range(0,getWidth(pic1)):
    for y in range(0,getHeight(pic1)):
      if x == 0 or x == (width - 1) or y == 0 or y == (height - 1):
        setColor(getPixel(pic1,x,y), black)
  
  for x in range(1, getWidth(pic1)-1):
      for y in range(1, getHeight(pic1)-1):        
          if random.random() < pInit:
            setColor(getPixel(pic1,x,y),green)
          
  return(pic1)
  
  
# counts the number of live trees around a cerin pixe(green pixels)
# then adds  1 to the varible numTrees, and returns this new value. 
def countTrees(pic2,x,y):
  numTrees = 0
  if getColor(getPixel(pic2,x+1,y)) == green:
    numTrees = numTrees + 1
  if getColor(getPixel(pic2,x-1,y)) == green:
    numTrees = numTrees + 1
  if getColor(getPixel(pic2,x,y+1)) == green:
    numTrees = numTrees + 1
  if getColor(getPixel(pic2,x,y-1)) == green:
    numTrees = numTrees + 1
  if getColor(getPixel(pic2,x+1,y+1)) == green:
    numTrees = numTrees + 1
  if getColor(getPixel(pic2,x+1,y-1)) == green:
    numTrees = numTrees + 1
  if getColor(getPixel(pic2,x-1,y-1)) == green:
    numTrees = numTrees + 1
  if getColor(getPixel(pic2,x-1,y+1)) == green:
    numTrees = numTrees + 1
  return numTrees
  
#counts the pixels around the selected pixel like bfore
#but checks for the color red, then returns if this is true or not
def catchingFire(pic2,x,y):
  if getColor(getPixel(pic2,x+1,y)) == red:
    return true
  elif getColor(getPixel(pic2,x-1,y)) ==red:
    return true
  elif getColor(getPixel(pic2,x,y+1)) == red:
    return true
  elif getColor(getPixel(pic2,x,y-1)) == red:
    return true
  elif getColor(getPixel(pic2,x+1,y+1)) == red:
    return true
  elif getColor(getPixel(pic2,x+1,y-1)) == red:
    return true
  elif getColor(getPixel(pic2,x-1,y-1)) == red:
    return true
  elif getColor(getPixel(pic2,x-1,y+1)) == red:
    return true
  else:
    return false   