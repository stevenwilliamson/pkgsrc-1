# $NetBSD: Makefile,v 1.10 2017/09/18 09:52:57 maya Exp $

DISTNAME=	vsqlite++-0.3.13
PKGREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://evilissimo.fedorapeople.org/releases/vsqlite--/0.3.13/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vsqlite.virtuosic-bytes.com/
COMMENT=	C++ SQLite wrapper library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
