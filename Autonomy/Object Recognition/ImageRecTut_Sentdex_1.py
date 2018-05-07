import numpy as np
import matplotlib.pyplot as mp
from PIL import Image as img
import time
i=img.open('numbers/y0.3.png')
iar=np.asarray(i)
i2=img.open('numbers/y0.4.png')
iar2=np.asarray(i2)            
i3=img.open('numbers/y0.5.png')
iar3=np.asarray(i3)            
i4=img.open('numbers/y0.5.png')
iar4=np.asarray(i4)            
def threshold(arr):
    balance=[]
    newarr=arr
    for row in arr:
        for pix in row:
            avg=int(sum(pix[0:3])/3)
            balance.append(avg)
    bal=int(sum(balance)/len(balance))
    for r in newarr:
        for pixx in r:
            if int(sum(pixx[0:3])/3)>=bal:
                pixx[0]=255
                pixx[1]=255
                pixx[2]=255
                pixx[3]=255
            else :
                pixx[0]=0
                pixx[1]=0
                pixx[2]=0
                pixx[3]=255
    return newarr             
a=iar
threshold(a)             
fig=mp.figure()
ax1=mp.subplot2grid((8,8),(0,0),rowspan= 4,colspan=4)
ax2=mp.subplot2grid((8,8),(4,0),rowspan= 4,colspan=4)
ax3=mp.subplot2grid((8,8),(0,4),rowspan= 4,colspan=4)
ax4=mp.subplot2grid((8,8),(4,4),rowspan= 4,colspan=4)     
ax1.imshow(iar)
ax2.imshow(iar2)
ax3.imshow(iar3)
ax4.imshow(iar4)
mp.show()
