pkgname="openutils-map"
pkgver="1.8.0"
pkgrel="3"
pkgdesc="MAP : The Unique Element Container Library [NOT-MAINTAINED]"
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("3f77b4b5e454a823bbc2829f475f58c97463f5d6d35dfc634c322f26ec1b4794656dfc5fb4114678b8b57e5c04c3f196c05a64308ec53d68be107d2b0a721925")

package() {
	echo "MAP : The Unique Element Container Library [NOT-MAINTAINED]"
	mkdir -p "${pkgdir}/usr/include/openutils/map"
	cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
	echo "Done!"
}
