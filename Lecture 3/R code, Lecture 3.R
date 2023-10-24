#create file with only females older than 17 years of age
kc <- KungCensus
kaf <- subset(kc, sex=="woman" & age > 18)

#One-sample t-test 
t.test(kaf$height, mu=155)
t.test(kaf$height, mu=155, conf.level=0.99)

#Two-sample t-test
t.test(kc$weight ~ kc$sex)

#Paired t-test
#first, install and run package ISwR
intake
t.test(intake$post, intake$pre, paired=T)
t.test(intake$pre, intake$post, paired=T)

