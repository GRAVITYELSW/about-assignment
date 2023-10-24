#Lecture 1
#histogram
hist(KungCensus$age)
summary(KungCensus$age)
hist(KungCensus$age, breaks=seq(0,85,1),
     main="Age", col="lightgreen",
     xlab="age (years)", ylab="number of people")

#plot
plot(KungCensus$height ~ KungCensus$age)
plot(KungCensus$height ~ KungCensus$age, pch=19, cex.axis=1.2, 
     col="blue", xlab="age (years)", 
     ylab="height")


#Lecture 2
1-pnorm(185, 180, 10)
1-pnorm(185, 180, 10)+pnorm(175, 180, 10)
pnorm(199, 180, 10) - pnorm(161, 180, 10)

pnorm(-1.96)
pnorm(-2.56)
qnorm(0.005)

#creating a file with adults only:
kungadultfemales <- subset(KungCensus, 
                           age > 18 & sex == "woman")
#or if you don't want to create a new file but only filter cases for the command 
hist(KungCensus$weight[KungCensus$age > 18  & KungCensus$sex == 'woman']) 

summary(kungadultfemales$weight)
length(kungadultfemales$weight)
sd(kungadultfemales$weight, na.rm = T)
pnorm(40, 42.07, 5.301835)
1-pnorm(60, 42.07, 5.301835)
pnorm(-3)
1- 2*pnorm(-3)


#Lecture 3
summary(kaf$height)
sd(kaf$height, na.rm=T)

t.test(kaf$weight, mu=40)
t.test(kaf$weight, mu=40, conf.level=0.99)

t.test(kc$weight ~ kc$sex, conf.level=0.99)
km <- subset(kc, sex=="man")
kw <- subset(kc, sex=="woman")
t.test(kw$weight, km$weight)

t.test(intake$post, intake$pre, paired=T, conf.level=0.99)
t.test(intake$post, intake$pre)
t.test(intake$post, intake$pre, conf.level=0.99)


t.test(kfm$weight ~ kfm$sex)
t.test(kfm$dl.milk ~ kfm$sex)
t.test(humanlongevity$longevity.women, 
       humanlongevity$longevity.men, 
       paired = T)

#Lecture 4
react
hist(react)
table(react)
length(react)
hist(react, breaks=seq(-10,9, 1))
shapiro.test(react)

# hange HDI to numeric on import
HDR2011$HDI <- as.numeric(HDR2011$HDI)

summary(HDR2011$HDI)
hist(HDR2011$HDI, breaks=seq(0.2, 1, 0.02), col="tomato")
shapiro.test(HDR2011$HDI)
mean(HDR2011$HDI, na.rm=T)
wilcox.test(HDR2011$HDI, mu=0.7, conf.int=T)

mean(zelazo$active)
mean(zelazo$ctr.8w)
wilcox.test(zelazo$active, zelazo$ctr.8w, 
            conf.int = T)

table(energy$stature)
tapply(energy$expend, energy$stature, mean)
wilcox.test(energy$expend ~ energy$stature, conf.int = T)

hr0 <- subset(heart.rate, time == 0)
hr60 <- subset(heart.rate, time == 60)
tapply(heart.rate$hr, heart.rate$time, mean)
wilcox.test(hr0$hr, hr60$hr, paired=T, conf.int=T)
wilcox.test(hr0$hr, hr60$hr, conf.int=T)


#Lecture 5
239/1.897
239-126
prop.test(113, 239)
77/1.943

prop.test(37, 77)

224/2.133
prop.test(c(113,119), c(239,224))
85/2.576

102/2.318
216 - ( 216/2.118)
102-44
prop.test(c(37, 58), c(77, 102))
prop.test(52, 85)
prop.test(c(120,114,113,118), c(254,216,239,224))
chisq.test(matrix(c(120,114,113,118,134,102,126,106),
                  nrow=4))


#Lecture 6
tapply(SBR2$size, SBR2$delivery, mean, na.rm=T)
tapply(SBR2$size, SBR2$delivery, hist, 
       breaks = seq(0, 8000, 100))
tapply(SBR2$size, SBR2$delivery, 
       function(x) shapiro.test(sample(x, 4999)))
tapply(SBR2$size, SBR2$delivery, var, na.rm=T)
bartlett.test(SBR2$size ~ SBR2$delivery)
oneway.test(SBR2$size ~ SBR2$delivery)
pairwise.t.test(SBR2$size, SBR2$delivery, pool.sd=F)
kruskal.test(SBR2$size ~ SBR2$delivery)
pairwise.wilcox.test(SBR2$size, SBR2$delivery)

#Lecture 7
power.t.test(power=0.8, delta=2, sd=2)
power.t.test(n=40, delta=2, sd=7)


power.t.test(power=0.9, sd=400, delta = 3300*0.05)
power.t.test(power=0.9, sd=400, delta = 3300*0.1)
power.prop.test(power=0.8, p1=0.4724409, p2=0.5277778)

#Lecture 8
hist(HDR2011$lifespan)
hist(as.numeric(HDR2011$schooling))
hist(as.numeric(HDR2011$income))
cor.test(HDR2011$lifespan, as.numeric(HDR2011$schooling))
cor.test(as.numeric(HDR2011$schooling), as.numeric(HDR2011$income))

plot(weight ~ height, data=Kungadultmales)
reg1 <- lm(weight ~ height, data=Kungadultmales)
summary(reg1)
0.429**0.5
cor.test(Kungadultmales$weight, Kungadultmales$height)
abline(reg1)

#linear model
# weight = -49.8194 + 0.61377*(height)

165*0.61377-49.8194

abline(v=165, lty=2, col="red")
abline(h=51.45, lty=2, col="red")
points(165, 51.45, pch=19, col="red", cex=2)
