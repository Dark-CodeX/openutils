pkgname="openutils-sstring"
pkgver="2.7.0"
pkgrel="8"
pkgdesc="SSTRING : The String Manipulation Library"
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=("8d6a2fc0bba9a90d497c9db25f3dd81b2d3f2953822b5892ae3ee2d623d739c6a532c4f4f154b5543c2a327cfdf4e603ae3c564e0f23b4bed1e823dee456bcbd")

package() {
	echo "SSTRING : The String Manipulation Library"
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
