
heap <- setRefClass('heap',
                     fields = list(ele = 'list', comp='function'),
                     methods = list(
                      
                      push=function(x){
                         ele[length(ele)+1] <<- x
                         swap = function(i, j){
                           temp = ele[i]
                           ele[i] <<- ele[j]
                           ele[j] <<- temp  
                         }
                         
                         shiftUp = function(i){
                           while(i > 1 ){
                             par = i/2

                             if(comp(ele[[i]], ele[[par]])){
                               swap(par, i)
                                i = par
                             }
                             else{
                               break
                             }
                           }
                         }
                         
                         shiftUp(length(ele))
                       },
                      
                      pop=function(){
                         if(length(ele)<1)
                           return 
                         swap = function(i, j){
                           temp = ele[i]
                           ele[i] <<- ele[j]
                           ele[j] <<- temp  
                         }
                         swap(1, length(ele) )
                         
                         ele <<- ele[-length(ele)]
                         
                         
                         shiftDown = function(i){
                           
                           while(i < length(ele)){
                             child = 2*i
                             if(child+1 <= length(ele) & comp(ele[child+1] , ele[child]))
                               child = child + 1
                             
                             if(comp(ele[child], ele[i])){
                               swap(i, child)
                               i = child
                             }
                             else{
                               break
                             }
                           }
                         }
                         
                         if(length(ele) > 1)
                           shiftDown(1)
                       },
                      
                      top=function(){
                         if(length(ele)>0)
                           return (ele[1])
                       },
                      
                      empty=function(){
                         return (length(ele)==0)
                       },
                       
                      size=function(){
                         return (length(ele))
                       },
                      
                      show=function(){
                          for (i in ele){
                            cat(i,' ')
                          }
                          cat('\nsize : ', size(), '\n')
                      }                    
                    )
)
#setMethod("heap","show",)

h <- heap(comp=function(a,b){
  as.numeric(a) > as.numeric(b)
})

for (i in 5:1){
  h$push(i)
}

h$pop()
h$size()
h

h$top()
h$ele
