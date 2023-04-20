pkgname="openutils-sstring"
pkgver="2.7.0"
pkgrel="8"
pkgdesc="SSTRING : The String Manipulation Library"
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=("5f9fc560283f969a8fa83834ef18b5feb5bab38f70a02d470165bd4f2d9655efe360d898641c5eec74792ab28b3847421e306013d6223571acca3b5beb0d1949")

package() {
	echo "SSTRING : The String Manipulation Library"
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
