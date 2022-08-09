pkgname="openutils-returns"
pkgver="1.2.3"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh" "https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh")

sha512sums=("14cf818708907505397502f5e53bd1bd38f7d4e5c6a14533c6a04f84bdbe820ea536017cb5c02e5cb20230a4ccc3fe85b16ef48956125993b87e063e6bb28f82" "7bd19bdba65d50f92eb23c7ab4a30729e14fec4e2134232c16f49e6370522ccc51f560753c190351e3cc1768c0575d2147a240de8ac9ecfdf78e85a5b746677b")

package() {
	echo "Memory Safe Value Returning Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/returns"
	cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
	echo "Done!"
}
