#checking for normality
hist(kaf$height, breaks=seq(130,170,1))
hist(kc$height, breaks=seq(50,190,1))

#normality tests
shapiro.test(kaf$height)
shapiro.test(kc$height)
hist(intake$post, breaks=seq(3500, 8000,100))
shapiro.test(intake$post) #for this you need to load library ISwR 

#Wilcoxon one-sample
wilcox.test(intake$post, mu=6500, conf.int=T)

#Wilcoxon two independent samples
#creating file with babies only
kb <- subset(kc, birthyear>1967)
tapply(kb$weight, kb$sex, mean, na.rm=T)
table(kb$sex)

wilcox.test(kb$weight ~ kb$sex, conf.int=T)

#Wilcoxon paired samples
wilcox.test(intake$pre, intake$post, paired=T, conf.int=T)


