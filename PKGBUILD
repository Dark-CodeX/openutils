pkgname="openutils-date_time"
pkgver="1.1.0"
pkgrel="1"
pkgdesc="DATE-TIME : The Date/Time Management Library"
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"e8045e99f72a9d1dbf52b2419dc3151e2892c1f810d82620fde72b7b4bde1d0412cae820a99b67c0e67315fe37a23b5f4b98bb34b7498d91fdce837773ebbea4"
	"1c5059a4d5dadfb9b85a981d702899c7989937e314f0d6feb7424efeae4c48560b7e5ecab1ff57cbf7f0b2d082efbf950d4fc9dc68ddf4d37ccd00a816e81ed5")

package() {
	echo "DATE-TIME : The Date/Time Management Library"
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
