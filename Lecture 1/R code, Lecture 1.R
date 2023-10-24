#descriptive statistics
#mean
mean(KungCensus$weight, na.rm=T)
range(KungCensus$weight, na.rm=T)

#median
median(KungCensus$weight, na.rm=T)

#mode (most frequent value)
table(KungCensus$weight)
table(as.integer(KungCensus$weight))
sort(table(as.integer(KungCensus$weight)))

#summaries
summary(KungCensus$weight)
summary(KungCensus$sex)
table(KungCensus$sex)
summary(KungCensus)

#measures of dispersal
var(weight, na.rm=T) #why doesn't that work?
var(KungCensus$weight, na.rm=T)
sd(KungCensus$weight, na.rm=T)

#histogram
hist(KungCensus$weight)
hist(KungCensus$weight, breaks=seq(0,65,1), freq=T,
     main="Weight of the !Kung", col="blue",
     xlab="weight (kg)", ylab="number of people")
#plot
plot(KungCensus$weight ~ KungCensus$age)
plot(KungCensus$weight ~ KungCensus$age, cex.axis=1.2, main = "My first plot",
     col="grey65", xlab="age (years)", ylab="weight")

#list of all colours; try a few!
colours()

