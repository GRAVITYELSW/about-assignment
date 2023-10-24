#ANOVA, Bartlett's test
table(SBR2$year)
tapply(SBR2$head, SBR2$year, mean, na.rm=T)
tapply(SBR2$head, SBR2$year, var, na.rm=T)
tapply(SBR2$head, SBR2$year, hist, breaks = seq(5, 80, 1))
tapply(SBR2$head, SBR2$year, shapiro.test)
bartlett.test(SBR2$head ~ SBR2$year)

#ANOVA
class(SBR2$year)
levels(SBR2$year) # to check for factor levels
class(SBR2$delivery)
anova(lm(SBR2$head ~ SBR2$year))

pairwise.t.test(SBR2$head, SBR2$year)

#ANOVA with oneway()
tapply(SBR3$head, SBR3$delivery, mean, na.rm=T)
tapply(SBR3$head, SBR3$delivery, var, na.rm=T)
tapply(SBR3$head, SBR3$delivery, hist, breaks = seq(5, 80, 1))
tapply(SBR3$head, SBR3$delivery, hist, shapiro.test)
bartlett.test(SBR3$head ~ SBR3$delivery)
oneway.test(SBR3$head ~ SBR3$delivery)
pairwise.t.test(SBR3$head, SBR3$delivery, pool.sd=F)

#Kruskal-Wallis test
tapply(brain$PrebyT, brain$group, mean, na.rm=T)
bartlett.test(brain$PrebyT ~ brain$group)
summary(brain$group)
kruskal.test(brain$PrebyT ~ brain$group)
pairwise.wilcox.test(brain$PrebyT, brain$group)

#Two-way ANOVA
anova(lm(SBR2$head ~ SBR2$year+SBR2$delivery))


