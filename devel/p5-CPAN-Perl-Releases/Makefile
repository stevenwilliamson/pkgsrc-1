# $NetBSD: Makefile,v 1.44 2017/09/17 09:46:11 wiz Exp $

DISTNAME=	CPAN-Perl-Releases-3.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Perl-Releases/
COMMENT=	Mapping Perl releases on CPAN to the location of the tarballs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CPAN/Perl/Releases/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
